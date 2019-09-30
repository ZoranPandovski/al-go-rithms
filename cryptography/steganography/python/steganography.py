import getopt
import math
import os
import struct
import sys
import wave


def hide(sound_path, file_path, output_path, num_lsb):
    sound = wave.open(sound_path, "r")
    
    params = sound.getparams()
    num_channels = sound.getnchannels()
    sample_width = sound.getsampwidth()
    num_frames = sound.getnframes()
    num_samples = num_frames * num_channels
    
    max_bytes_to_hide = (num_samples * num_lsb) // 8
    filesize = os.stat(file_path).st_size
    
    if filesize > max_bytes_to_hide:
        required_LSBs = math.ceil(filesize * 8 / num_samples)
        raise ValueError("Input file too large to hide, "
                         "requires {} LSBs, using {}"
                         .format(required_LSBs, num_lsb))
    
    print("Using {} B out of {} B".format(filesize, max_bytes_to_hide))
    print(sample_width)
    if sample_width == 1:  # samples are unsigned 8-bit integers
        fmt = "{}B".format(num_samples)
        mask = (1 << 8) - (1 << num_lsb)
        min_sample = -(1 << 8)
    elif sample_width == 2:  # samples are signed 16-bit integers
        fmt = "{}h".format(num_samples)
        mask = (1 << 15) - (1 << num_lsb)
        min_sample = -(1 << 15)
    else:
        raise ValueError("File has an unsupported bit-depth")
    
    raw_data = list(struct.unpack(fmt, sound.readframes(num_frames)))
    sound.close()
    
    input_data = memoryview(open(file_path, "rb").read())
    data_index = 0
    sound_index = 0
    
    values = []
    buffer = 0
    buffer_length = 0
    done = False
    print(input_data[1])
    
    while not done:
        while buffer_length < num_lsb and data_index // 8 < len(input_data):
            buffer += (input_data[data_index // 8] >> (data_index % 8)
                        ) << buffer_length
            bits_added = 8 - (data_index % 8)
            buffer_length += bits_added
            data_index += bits_added
            
        current_data = buffer % (1 << num_lsb)
        buffer >>= num_lsb
        buffer_length -= num_lsb

        while (sound_index < len(raw_data) and
               raw_data[sound_index] == min_sample):
            values.append(struct.pack(fmt[-1], raw_data[sound_index]))
            sound_index += 1

        if sound_index < len(raw_data):
            current_sample = raw_data[sound_index]
            sound_index += 1

            sign = 1
            if current_sample < 0:
                current_sample = -current_sample
                sign = -1

            altered_sample = sign * ((current_sample & mask) | current_data)

            values.append(struct.pack(fmt[-1], altered_sample))

        if data_index // 8 >= len(input_data) and buffer_length <= 0:
            done = True
        
    while sound_index < len(raw_data):
        values.append(struct.pack(fmt[-1], raw_data[sound_index]))
        sound_index += 1
    
    sound_steg = wave.open(output_path, "w")
    sound_steg.setparams(params)
    sound_steg.writeframes(b"".join(values))
    sound_steg.close()


def recover(sound_path, output_path, num_lsb, bytes_to_recover):

    sound = wave.open(sound_path, "r")
    
    num_channels = sound.getnchannels()
    sample_width = sound.getsampwidth()
    num_frames = sound.getnframes()
    num_samples = num_frames * num_channels
    
    if (sample_width == 1):  # samples 8 bits
        fmt = "{}B".format(num_samples)
        min_sample = -(1 << 8)
    elif (sample_width == 2):  # samples 16 bits
        fmt = "{}h".format(num_samples)
        min_sample = -(1 << 15)
    else:
        raise ValueError("File has an unsupported bit-depth")
    
    raw_data = list(struct.unpack(fmt, sound.readframes(num_frames)))
    mask = (1 << num_lsb) - 1
    output_file = open(output_path, "wb+")
    
    data = bytearray()
    sound_index = 0 
    buffer = 0
    buffer_length = 0
    
    while (bytes_to_recover > 0):
        
        next_sample = raw_data[sound_index]
        if (next_sample != min_sample):
            buffer += (abs(next_sample) & mask) << buffer_length
            buffer_length += num_lsb
        sound_index += 1
        
        while (buffer_length >= 8 and bytes_to_recover > 0):
            current_data = buffer % (1 << 8)
            buffer >>= 8
            buffer_length -= 8
            data += struct.pack('1B', current_data)
            bytes_to_recover -= 1

    output_file.write(bytes(data))
    output_file.close()
