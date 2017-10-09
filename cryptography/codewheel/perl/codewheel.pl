#!/usr/bin/env perl

use List::MoreUtils qw(firstidx);
use List::Util qw(max);

# useful for debugging, prints a wheel as a single line
sub dump_wheels
{
  my $wheel_set = shift;
  foreach my $wheel (@$wheel_set) {
    print join('', @$wheel) . "\n";
  }
}

# returns the nth prime
sub nth_prime
{
  my $num = shift;

  return 2 if $num <= 1;
  return 541 if $num >= 100;

  my @primes = (
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541);

  return $primes[$num - 1];
}

# the letters used in the cipher
sub letters
{
  return [map {chr} (ord(' ') .. ord('~'))];
}

# rotates a wheel, left or right
sub rotate_wheel
{
  my ($wheel, $num, $rotate_left) = @_;

  my $i = 0;
  while ($i < $num) {
    if ($rotate_left) {
      my $letter = shift @$wheel;
      push @$wheel, $letter;
    } else {
      my $letter = pop @$wheel;
      unshift @$wheel, $letter;
    }
    $i++;
  };

  return $wheel;
}

# initialize the wheels
sub initialize_wheels
{
  my $num_wheels = shift;

  my $i = 0;
  while ($i < $num_wheels) {
    if ($i) {
      # subsequent wheels start shifted, odd wheels shift left
      $wheel_set->[$i] = rotate_wheel(letters(), nth_prime($i + 1), $i % 2);
    } else {
      # initial wheel starts normal
      $wheel_set->[$i] = letters();
    }
    $i++;
  }

  return $wheel_set;
}

# encode / decode a letter using the wheel set
sub read_wheels
{
  my ($wheel_set, $letter, $encode) = @_;
  my $encoded_letter;

  # ensure we can encode the letter, otherwise just emit it unchanged.
  return $letter unless firstidx {$_ eq $letter} (letters());

  # encoding reads top down, decoding reads bottom up
  if ($encode) {
    my $idx = firstidx { $_ eq $letter } @{$wheel_set->[0]};
    $encoded_letter = $wheel_set->[$#wheel_set][$idx];
  } else {
    my $idx = firstidx { $_ eq $letter } @{$wheel_set->[$#wheel_set]};
    $encoded_letter = $wheel_set->[0][$idx];
  }

  return $encoded_letter;
}

# rotate all the wheels
sub rotate_wheels
{
  my ($wheel_set, $num_wheels) = @_;
  my $i = 0;

  # odd wheels rotate left
  while ($i < $num_wheels) {
    $wheel_set->[$i] = rotate_wheel($wheel_set->[$i], nth_prime($i + 1), $i % 2);
    $i++;
  }

  return $wheel_set;
}

# encrypt the text
sub encrypt
{
  my ($text, $num_wheels) = @_;
  
  $num_wheels = 2 unless $num_wheels > 2;

  my $wheel_set = initialize_wheels($num_wheels);
  
  my $encoded_text;
  foreach my $letter (split(//, $text)) {
    $encoded_text .= read_wheels($wheel_set, $letter, 1);
    $wheel_set = rotate_wheels($wheel_set, $num_wheels);
  }

  return $encoded_text;
}

sub decrypt
{
  my ($text, $num_wheels) = @_;
  
  $num_wheels = 2 unless $num_wheels > 2;
  my $wheel_set = initialize_wheels($num_wheels);
  
  my $decoded_text;
  foreach my $letter (split(//, $text)) {
    $decoded_text .= read_wheels($wheel_set, $letter, 0);
    $wheel_set = rotate_wheels($wheel_set, $num_wheels);
  }

  return $decoded_text;
}

my $num_wheels = max(2, int(rand(101)));
my $text = 'This is a test.  This is only a test.';

my $encrypted = encrypt($text, $num_wheels);
my $decrypted = decrypt($encrypted, $num_wheels);
print "Decrypted matches original\n" if $decrypted eq $text;
