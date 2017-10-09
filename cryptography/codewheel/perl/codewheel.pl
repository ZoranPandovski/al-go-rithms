#!/usr/bin/env perl

use List::MoreUtils qw(firstidx);
use List::Util qw(max);

sub letters
{
  return [map {chr} (ord(' ') .. ord('~'))];
}

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

sub read_wheels
{
  my ($wheel_set, $letter, $pos, $encode) = @_;
  my $encoded_letter;

  # ensure we can encode the letter, otherwise just emit it unchanged.
  return $letter unless firstidx {$_ eq $letter} (letters());

  # encoding reads top down, decoding reads bottom up
  my $chosen = $pos % (scalar (@$wheel_set) - 1);
  if ($encode) {
    my $idx = firstidx { $_ eq $letter } @{$wheel_set->[$chosen]};
    $encoded_letter = $wheel_set->[$#wheel_set][$idx];
  } else {
    my $idx = firstidx { $_ eq $letter } @{$wheel_set->[$#wheel_set]};
    $encoded_letter = $wheel_set->[$chosen][$idx];
  }

  return $encoded_letter;
}

sub rotate_wheels
{
  my $wheel_set = shift;
  my $i = 0;

  # odd wheels rotate left
  while ($i < scalar (@$wheel_set)) {
    $wheel_set->[$i] = rotate_wheel($wheel_set->[$i], nth_prime($i + 1), $i % 2);
    $i++;
  }

  return $wheel_set;
}

sub encrypt
{
  my ($data, $num_wheels) = @_;
  
  $num_wheels = 2 unless $num_wheels > 2;

  my $wheel_set = initialize_wheels($num_wheels);
  
  my $encoded_data;

  my @chars = split(//, $data);
  for (my $pos = 0; $pos < scalar @chars; $pos++) {
    $encoded_data .= read_wheels($wheel_set, $chars[$pos], $pos, 1);
    $wheel_set = rotate_wheels($wheel_set);
  }

  return $encoded_data;
}

sub decrypt
{
  my ($data, $num_wheels) = @_;
  
  $num_wheels = 2 unless $num_wheels > 2;
  my $wheel_set = initialize_wheels($num_wheels);
  
  my $decoded_data;
  my @chars = split(//, $data);
  for (my $pos = 0; $pos < scalar @chars; $pos++) {
    $decoded_data .= read_wheels($wheel_set, $chars[$pos], $pos, 0);
    $wheel_set = rotate_wheels($wheel_set);
  }

  return $decoded_data;
}

my $num_wheels = max(2, int(rand(101)));
my $text = 'This is a test.  This is only a test. If this had been a real emergency, then something important would be in this message.';

my $encrypted = encrypt($text, $num_wheels);
my $decrypted = decrypt($encrypted, $num_wheels);

print "Decrypted matches original\n" if $decrypted eq $text;
