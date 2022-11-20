# bit-map-filter
This is an example of using C to iterate pixels in a .bmp file and, depending upon option passed in at command line, converts the original .bmp file into
an out.bmp file that is greyscaled, sepia, relfected or blurred.

command line arguments to run in same directory as 'filter' and images/
./filter -g images/yard.bmp out.bmp //greyscale
./filter -s images/yard.bmp out.bmp //sepia
./filter -r images/yard.bmp out.bmp //reflected
./filter -b images/yard.bmp out.bmp //blurred
