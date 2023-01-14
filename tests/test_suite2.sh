#! /bin/bash

SIZE=1 make memtest
make fclean
SIZE=10 make memtest
make fclean
SIZE=16 make memtest
make fclean
# SIZE=42 make memtest
# make fclean
# SIZE=999 make memtest
# make fclean
# SIZE=20230 make memtest
# make fclean
SIZE=100000000 make memtest
make fclean