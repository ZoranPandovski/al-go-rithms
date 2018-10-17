#!/usr/bin/perl -w

use strict;

my @array;
my $low = 0;
my $mid;
my $found_key = 0;
my $num;
my $key;
my $index;

@array = ( 5, 10, 30, 4, -3, 18, 101, 500, 6, 15 );
@array = sort { $a <=> $b } @array;

my $high = $#array;
print "@array\n";

print "Please enter key to search for: ";
chomp( $key = <STDIN> );

while( ( $low <= $high ) && !$found_key ) {
  $mid = ( $low + $high ) / 2;
  if( $key == $array[$mid] ) {
    $found_key = 1;
    $index = int( $mid );
  }

  elsif( $key < $array[$mid] ) {
    $high = $mid - 1;
  }

  else {
    $low = $mid + 1;
  }
}

if( $found_key ) {
  print "$key is at position: $index\n";
}

else {
  print "Sorry. I could not find: $key"; }