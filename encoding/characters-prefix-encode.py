#!/usr/bin/python
###############################################################################
# Given a string, encode it using a prefix method and output the string
# pad if necessary
# For example, if the string is "abbc", the output should be abc acb 10101001
# Where, a -> "1", c -> "01", b -> "001" 
###############################################################################

h = {}

s = raw_input("Enter string to encode: ")

def encode(s):
	chars = list(s)

	# count
	for c in chars:
		if h.has_key(c):
			h[c] = h[c] + 1
		else:
			h[c] = 0
	chars = sorted(h, key=lambda c: h[c])
	chars.reverse()

	print "characters sorted by frequency (more to less): " + str(chars)

	# create encoding map
	m = {}
	for i in range(len(chars)):
		enc = "0" * i
		enc = enc + "1"
		m[chars[i]] = enc

	print "map for encoding: " + str(m)

	# encode
	enc = ""
	for c in s:
		enc = enc + m[c]

	# padding to 8 bits
	enc = enc + (8-(len(enc)%8)) * "0"
	
	# add header
	hdr = ""
	for c in chars:
		hdr = hdr + c

	enc = hdr + " " + enc

	print "final encoded string: " + enc


encode(s)
