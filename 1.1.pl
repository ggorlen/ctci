# 1.1
# 
# Implement an algorithm to determine if a string has all unique characters.
# What if you cannot use additional data structures?

use strict;
use warnings;

sub is_unique {
    my @letters = split "", shift;
    my %unique_letters;
    @unique_letters{@letters} = ();
    my @unique = keys %unique_letters;
    return @unique == @letters;
}

sub is_unique {
    my $s = shift;

    for (my $i = 0; $i < length $s; $i++) {
        for (my $j = $i + 1; $j < length $s; $j++) {
            if (substr($s, $i, 1) eq substr($s, $j, 1)) {
                return 0;
            }
        }
    }

    return 1;
}

printf "axab: %s\n", is_unique('axab') ? "true" : "false";
printf "axb: %s\n", is_unique('axb') ? "true" : "false";
