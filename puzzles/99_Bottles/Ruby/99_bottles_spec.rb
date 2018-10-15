require_relative '99_bottles'

describe "99 bottles" do
  let(:song) { File.read("full_song.txt") }

  it "sings the complete song" do

    expect { lyric_99_bottles(99) }.to output(song).to_stdout
  end
end
