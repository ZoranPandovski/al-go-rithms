package main

// Source: exercism/problem-specifications
// Commit: b5d154b hamming: move inputs (strand1, strand2) to input object
// Problem Specifications Version: 2.1.0

var testCases = []struct {
	s1   string
	s2   string
	want int
}{
	{ // empty strands
		"",
		"",
		0,
	},
	{ // identical strands
		"A",
		"A",
		0,
	},
	{ // long identical strands
		"GGACTGA",
		"GGACTGA",
		0,
	},
	{ // complete distance in single nucleotide strands
		"A",
		"G",
		1,
	},
	{ // complete distance in small strands
		"AG",
		"CT",
		2,
	},
	{ // small distance in small strands
		"AT",
		"CT",
		1,
	},
	{ // small distance
		"GGACG",
		"GGTCG",
		1,
	},
	{ // small distance in long strands
		"ACCAGGG",
		"ACTATGG",
		2,
	},
	{ // non-unique character in first strand
		"AAG",
		"AAA",
		1,
	},
	{ // non-unique character in second strand
		"AAA",
		"AAG",
		1,
	},
	{ // same nucleotides in different positions
		"TAG",
		"GAT",
		2,
	},
	{ // large distance
		"GATACA",
		"GCATAA",
		4,
	},
	{ // large distance in off-by-one strand
		"GGACGGATTCTG",
		"AGGACGGATTCT",
		9,
	},
	{ // disallow first strand longer
		"AATG",
		"AAA",
		-1,
	},
	{ // disallow second strand longer
		"ATA",
		"AGTG",
		-1,
	},
}
