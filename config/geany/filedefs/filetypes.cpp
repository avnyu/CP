[build-menu]
FT_00_LB=_Compile
FT_00_CM=g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result
FT_00_WD=
FT_01_LB=_Build
FT_01_CM=g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=time -p "./%e" < in
EX_00_WD=
EX_01_LB=
EX_01_CM=
EX_01_WD=
