# > file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# > file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# > file | cat < no_such_file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: no_such_file: No such file or directory
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# > file | cat < no_such_file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo hello > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> hello
### minishell result
---
# echo hello > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo hello > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo hello >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> hello
> hello
### minishell result
---
# echo hello >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo hello >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> Makefile
> README.md
> a
> builtin
> env
> err1.txt
> err2.txt
> err3.txt
> exec
> expander
> file
> lexer
> libft
> log
> main.c
> main.o
> minishell.h
> out1.txt
> out2.txt
> out3.txt
> parser
> script
> signal
> tags
> tests
> typescript
> utils
> workspace
### minishell result
---
# ls > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> Makefile
> README.md
> a
> builtin
> env
> err1.txt
> err2.txt
> err3.txt
> exec
> expander
> file
> lexer
> libft
> log
> main.c
> main.o
> minishell.h
> out1.txt
> out2.txt
> out3.txt
> parser
> script
> signal
> tags
> tests
> typescript
> utils
> workspace
> Makefile
> README.md
> a
> builtin
> env
> err1.txt
> err2.txt
> err3.txt
> exec
> expander
> file
> lexer
> libft
> log
> main.c
> main.o
> minishell.h
> out1.txt
> out2.txt
> out3.txt
> parser
> script
> signal
> tags
> tests
> typescript
> utils
> workspace
### minishell result
---
# ls >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls no_such_file > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> ls: no_such_file: No such file or directory
### minishell result
---
# ls no_such_file > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls no_such_file > out1.txt > out2.txt > out3.txt 2> err1.txt 2> err2.txt 2> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls no_such_file >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> ls: no_such_file: No such file or directory
> ls: no_such_file: No such file or directory
### minishell result
---
# ls no_such_file >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls no_such_file >> out1.txt >> out2.txt >> out3.txt 2>> err1.txt 2>> err2.txt 2>> err3.txt; cat out1.txt out2.txt out3.txt err1.txt err2.txt err3.txt
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo a > out; echo b >> out; echo c >> out; echo d >> out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> a
> b
> c
> d
### minishell result
---
# echo a > out; echo b >> out; echo c >> out; echo d >> out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a > out; echo b >> out; echo c >> out; echo d >> out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo a > out; echo b >> out; echo c >> out; echo d > out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> d
### minishell result
---
# echo a > out; echo b >> out; echo c >> out; echo d > out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a > out; echo b >> out; echo c >> out; echo d > out; cat out
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo hello 2147483647> file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: 2147483647: Bad file descriptor
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo hello 2147483647> file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo hello 2147483648> file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: file descriptor out of range: Bad file descriptor
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo hello 2147483648> file
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo a > $NO_ENV | echo b, unset NO_ENV
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> b, unset NO_ENV
### minishell result
---
# echo a > $NO_ENV | echo b, unset NO_ENV
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: $NO_ENV: ambiguous redirect
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a > $NO_ENV | echo b, unset NO_ENV
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ./a.out 3> file3 2> file2 1> file1; cat file3 file2 file1, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> cat: file1,: No such file or directory
> cat: printf: No such file or directory
> cat: #include<unistd.h>nint main(){write(1, "fd1n", 4);write(2, "fd2n", 4);write(3, "fd3n", 4);}: No such file or directory
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ./a.out 3> file3 2> file2 1> file1; cat file3 file2 file1, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# ./a.out 1> file1 2> file2 3> file3; cat file1 file2 file3, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> cat: file3,: No such file or directory
> cat: printf: No such file or directory
> cat: #include<unistd.h>nint main(){write(1, "fd1n", 4);write(2, "fd2n", 4);write(3, "fd3n", 4);}: No such file or directory
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ./a.out 1> file1 2> file2 3> file3; cat file1 file2 file3, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo a 1> 1.txt 2> 2.txt 3> 3.txt; ./a.out 1>> 1.txt 2>> 2.txt 3>> 3.txt; cat 1.txt 2.txt 3.txt, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> cat: 3.txt,: No such file or directory
> cat: printf: No such file or directory
> cat: #include<unistd.h>nint main(){write(1, "fd1n", 4);write(2, "fd2n", 4);write(3, "fd3n", 4);}: No such file or directory
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a 1> 1.txt 2> 2.txt 3> 3.txt; ./a.out 1>> 1.txt 2>> 2.txt 3>> 3.txt; cat 1.txt 2.txt 3.txt, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo a 3> 3.txt 2> 2.txt 1> 1.txt 2> 2.txt 3> 3.txt; echo b 1>> 1.txt 2>> 2.txt 3>> 3.txt 2>> 2.txt 1>> 1.txt; ./a.out 1>> 1.txt 2>> 2.txt 3>> 3.txt 2>> 2.txt 1>> 1.txt; cat 1.txt 2.txt 3.txt, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> cat: 3.txt,: No such file or directory
> cat: printf: No such file or directory
> cat: #include<unistd.h>nint main(){write(1, "fd1n", 4);write(2, "fd2n", 4);write(3, "fd3n", 4);}: No such file or directory
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a 3> 3.txt 2> 2.txt 1> 1.txt 2> 2.txt 3> 3.txt; echo b 1>> 1.txt 2>> 2.txt 3>> 3.txt 2>> 2.txt 1>> 1.txt; ./a.out 1>> 1.txt 2>> 2.txt 3>> 3.txt 2>> 2.txt 1>> 1.txt; cat 1.txt 2.txt 3.txt, printf '#include<unistd.h>nint main(){write(1, "fd1\n", 4);write(2, "fd2\n", 4);write(3, "fd3\n", 4);}' > a.c && gcc a.c
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# echo a > f; echo b >> f; cat f f f >> ff; cat ff ff >> f; cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> a
> b
> a
> b
> a
> b
> a
> b
> a
> b
> a
> b
> a
> b
### minishell result
---
# echo a > f; echo b >> f; cat f f f >> ff; cat ff ff >> f; cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a > f; echo b >> f; cat f f f >> ff; cat ff ff >> f; cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f;cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> 1.txt
> 2.txt
> 3.txt
> Makefile
> README.md
> a
> a.c
> builtin
> env
> err1.txt
> err2.txt
> err3.txt
> exec
> expander
> f
> ff
> file
> file1
> file2
> file3
> lexer
> libft
> log
> main.c
> main.o
> minishell.h
> out
> out1.txt
> out2.txt
> out3.txt
> parser
> script
> signal
> tags
> tests
> typescript
> utils
> workspace
### minishell result
---
# ls>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f;cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f>f;cat f
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# ls>a>b>c>d>e>f>g>h>i>j>k>l>m>n>o>p>q>r>s>t>u>v>w>x>y>z>A>B>C>D>E>F>G>H>I>J>K>L>M>N>O>P>Q>R>S>T>U>V>W>X>Y>Z>aa>ab>ac>ad>ae>af>ag>ah>ai>aj>ak>al>am>an>ao>ap>aq>ar>as>at>au>av>aw>ax>ay>az>aA>aB>aC>aD>aE>aF>aG>aH>aI>aJ>aK>aL>aM>aN>aO>aP>aQ>aR>aS>aT>aU>aV;ls
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> 1.txt
> 2.txt
> 3.txt
> Makefile
> README.md
> a
> a.c
> aa
> ab
> ac
> ad
> ae
> af
> ag
> ah
> ai
> aj
> ak
> al
> am
> an
> ao
> ap
> aq
> ar
> as
> at
> au
> av
> aw
> ax
> ay
> az
> b
> builtin
> c
> d
> e
> env
> err1.txt
> err2.txt
> err3.txt
> exec
> expander
> f
> ff
> file
> file1
> file2
> file3
> g
> h
> i
> j
> k
> l
> lexer
> libft
> log
> m
> main.c
> main.o
> minishell.h
> n
> o
> out
> out1.txt
> out2.txt
> out3.txt
> p
> parser
> q
> r
> s
> script
> signal
> t
> tags
> tests
> typescript
> u
> utils
> v
> w
> workspace
> x
> y
> z
### minishell result
---
# ls>a>b>c>d>e>f>g>h>i>j>k>l>m>n>o>p>q>r>s>t>u>v>w>x>y>z>A>B>C>D>E>F>G>H>I>J>K>L>M>N>O>P>Q>R>S>T>U>V>W>X>Y>Z>aa>ab>ac>ad>ae>af>ag>ah>ai>aj>ak>al>am>an>ao>ap>aq>ar>as>at>au>av>aw>ax>ay>az>aA>aB>aC>aD>aE>aF>aG>aH>aI>aJ>aK>aL>aM>aN>aO>aP>aQ>aR>aS>aT>aU>aV;ls
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls>a>b>c>d>e>f>g>h>i>j>k>l>m>n>o>p>q>r>s>t>u>v>w>x>y>z>A>B>C>D>E>F>G>H>I>J>K>L>M>N>O>P>Q>R>S>T>U>V>W>X>Y>Z>aa>ab>ac>ad>ae>af>ag>ah>ai>aj>ak>al>am>an>ao>ap>aq>ar>as>at>au>av>aw>ax>ay>az>aA>aB>aC>aD>aE>aF>aG>aH>aI>aJ>aK>aL>aM>aN>aO>aP>aQ>aR>aS>aT>aU>aV;ls
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
