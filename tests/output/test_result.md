# export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x CPATH="/Users/hyoshie/.brew/opt/readline/include:"
> declare -x HISTFILE="/Users/hyoshie/.zsh_history"
> declare -x HISTSIZE="100000"
> declare -x HOME="/Users/hyoshie"
> declare -x HOMEBREW_CACHE="/tmp/hyoshie/Homebrew/Caches"
> declare -x HOMEBREW_TEMP="/tmp/hyoshie/Homebrew/Temp"
> declare -x LESS_TERMCAP_mb="[01;34m"
> declare -x LESS_TERMCAP_md="[01;34m"
> declare -x LESS_TERMCAP_me="[0m"
> declare -x LESS_TERMCAP_se="[0m"
> declare -x LESS_TERMCAP_so="[01;44;33m"
> declare -x LESS_TERMCAP_ue="[0m"
> declare -x LESS_TERMCAP_us="[01;33m"
> declare -x LOGNAME="hyoshie"
> declare -x MAIL="hyoshie@student.42tokyo.jp"
> declare -x MAKEFLAGS=""
> declare -x MAKELEVEL="1"
> declare -x MANPATH="/Users/hyoshie/.brew/Cellar/readline/8.1.1/share/man:"
> declare -x MFLAGS=""
> declare -x OLDPWD
> declare -x PATH="/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki:/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/Users/hyoshie/.brew/opt/fzf/bin"
> declare -x PWD="/Users/hyoshie/project/minish"
> declare -x SAVEHIST="100000"
> declare -x SHELL="/bin/zsh"
> declare -x SHLVL="4"
> declare -x SSH_CLIENT="10.51.0.30 56340 22"
> declare -x SSH_CONNECTION="10.51.0.30 56628 10.11.22.8 22"
> declare -x SSH_TTY="/dev/ttys000"
> declare -x TERM="screen"
> declare -x TERM_PROGRAM="tmux"
> declare -x TERM_PROGRAM_VERSION="3.2a"
> declare -x TMOUT="86400"
> declare -x TMPDIR="/var/folders/zz/zyxvpxvq6csfxvn_n0000sr80006f2/T/"
> declare -x TMUX="/private/tmp/tmux-6594/default,28350,0"
> declare -x TMUX_PANE="%6"
> declare -x USER="hyoshie"
> declare -x XDG_CONFIG_HOME="/Users/hyoshie/.config"
> declare -x __CF_USER_TEXT_ENCODING="0x19C2:0:0"
### minishell result: 
> 

---
# export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export 1 _+ _OK _2? _OK2=VAR =NG OK3=; export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x CPATH="/Users/hyoshie/.brew/opt/readline/include:"
> declare -x HISTFILE="/Users/hyoshie/.zsh_history"
> declare -x HISTSIZE="100000"
> declare -x HOME="/Users/hyoshie"
> declare -x HOMEBREW_CACHE="/tmp/hyoshie/Homebrew/Caches"
> declare -x HOMEBREW_TEMP="/tmp/hyoshie/Homebrew/Temp"
> declare -x LESS_TERMCAP_mb="[01;34m"
> declare -x LESS_TERMCAP_md="[01;34m"
> declare -x LESS_TERMCAP_me="[0m"
> declare -x LESS_TERMCAP_se="[0m"
> declare -x LESS_TERMCAP_so="[01;44;33m"
> declare -x LESS_TERMCAP_ue="[0m"
> declare -x LESS_TERMCAP_us="[01;33m"
> declare -x LOGNAME="hyoshie"
> declare -x MAIL="hyoshie@student.42tokyo.jp"
> declare -x MAKEFLAGS=""
> declare -x MAKELEVEL="1"
> declare -x MANPATH="/Users/hyoshie/.brew/Cellar/readline/8.1.1/share/man:"
> declare -x MFLAGS=""
> declare -x OK3=""
> declare -x OLDPWD
> declare -x PATH="/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki:/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/Users/hyoshie/.brew/opt/fzf/bin"
> declare -x PWD="/Users/hyoshie/project/minish"
> declare -x SAVEHIST="100000"
> declare -x SHELL="/bin/zsh"
> declare -x SHLVL="4"
> declare -x SSH_CLIENT="10.51.0.30 56340 22"
> declare -x SSH_CONNECTION="10.51.0.30 56628 10.11.22.8 22"
> declare -x SSH_TTY="/dev/ttys000"
> declare -x TERM="screen"
> declare -x TERM_PROGRAM="tmux"
> declare -x TERM_PROGRAM_VERSION="3.2a"
> declare -x TMOUT="86400"
> declare -x TMPDIR="/var/folders/zz/zyxvpxvq6csfxvn_n0000sr80006f2/T/"
> declare -x TMUX="/private/tmp/tmux-6594/default,28350,0"
> declare -x TMUX_PANE="%6"
> declare -x USER="hyoshie"
> declare -x XDG_CONFIG_HOME="/Users/hyoshie/.config"
> declare -x _OK
> declare -x _OK2="VAR"
> declare -x __CF_USER_TEXT_ENCODING="0x19C2:0:0"
### minishell result: 
> 

---
# export 1 _+ _OK _2? _OK2=VAR =NG OK3=; export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
> minishell: export: `1': not a valid identifier
> minishell: export: `_+': not a valid identifier
> minishell: export: `_2?': not a valid identifier
> minishell: export: `=NG': not a valid identifier
### minishell result: 
> minishell: export: '1': not a valid identifier
> minishell: export: '_+': not a valid identifier
> minishell: export: '_2?': not a valid identifier
> minishell: export: '=NG': not a valid identifier

---
# export 1 _+ _OK _2? _OK2=VAR =NG OK3=; export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export dquote='"' dollar='$' backslash='' backquote='`' newline='n'; export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x CPATH="/Users/hyoshie/.brew/opt/readline/include:"
> declare -x HISTFILE="/Users/hyoshie/.zsh_history"
> declare -x HISTSIZE="100000"
> declare -x HOME="/Users/hyoshie"
> declare -x HOMEBREW_CACHE="/tmp/hyoshie/Homebrew/Caches"
> declare -x HOMEBREW_TEMP="/tmp/hyoshie/Homebrew/Temp"
> declare -x LESS_TERMCAP_mb="[01;34m"
> declare -x LESS_TERMCAP_md="[01;34m"
> declare -x LESS_TERMCAP_me="[0m"
> declare -x LESS_TERMCAP_se="[0m"
> declare -x LESS_TERMCAP_so="[01;44;33m"
> declare -x LESS_TERMCAP_ue="[0m"
> declare -x LESS_TERMCAP_us="[01;33m"
> declare -x LOGNAME="hyoshie"
> declare -x MAIL="hyoshie@student.42tokyo.jp"
> declare -x MAKEFLAGS=""
> declare -x MAKELEVEL="1"
> declare -x MANPATH="/Users/hyoshie/.brew/Cellar/readline/8.1.1/share/man:"
> declare -x MFLAGS=""
> declare -x OLDPWD
> declare -x PATH="/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki:/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/Users/hyoshie/.brew/opt/fzf/bin"
> declare -x PWD="/Users/hyoshie/project/minish"
> declare -x SAVEHIST="100000"
> declare -x SHELL="/bin/zsh"
> declare -x SHLVL="4"
> declare -x SSH_CLIENT="10.51.0.30 56340 22"
> declare -x SSH_CONNECTION="10.51.0.30 56628 10.11.22.8 22"
> declare -x SSH_TTY="/dev/ttys000"
> declare -x TERM="screen"
> declare -x TERM_PROGRAM="tmux"
> declare -x TERM_PROGRAM_VERSION="3.2a"
> declare -x TMOUT="86400"
> declare -x TMPDIR="/var/folders/zz/zyxvpxvq6csfxvn_n0000sr80006f2/T/"
> declare -x TMUX="/private/tmp/tmux-6594/default,28350,0"
> declare -x TMUX_PANE="%6"
> declare -x USER="hyoshie"
> declare -x XDG_CONFIG_HOME="/Users/hyoshie/.config"
> declare -x __CF_USER_TEXT_ENCODING="0x19C2:0:0"
> declare -x backquote="`"
> declare -x backslash=""
> declare -x dollar="$"
> declare -x dquote="""
> declare -x newline="n"
### minishell result: 
> 

---
# export dquote='"' dollar='$' backslash='' backquote='`' newline='n'; export | grep -v -E '^declare -x _='
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export APPEND=1; export APPEND+=2; export | grep APPEND
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x APPEND="12"
### minishell result: 
> 

---
# export APPEND=1; export APPEND+=2; export | grep APPEND
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export APPEND_NONE=1; export APPEND_NONE+=; export | grep APPEND_NONE
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x APPEND_NONE="1"
### minishell result: 
> 

---
# export APPEND_NONE=1; export APPEND_NONE+=; export | grep APPEND_NONE
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export APPEND_NONE=; export APPEND_NONE=; export APPEND_NONE+=; export | grep APPEND_NONE
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x APPEND_NONE=""
### minishell result: 
> 

---
# export APPEND_NONE=; export APPEND_NONE=; export APPEND_NONE+=; export | grep APPEND_NONE
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export APPEND_EMPTY=""; export APPEND_EMPTY=""; export APPEND_EMPTY=""; export | grep APPEND_EMPTY
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x APPEND_EMPTY=""
### minishell result: 
> 

---
# export APPEND_EMPTY=""; export APPEND_EMPTY=""; export APPEND_EMPTY=""; export | grep APPEND_EMPTY
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export OVERWRITE=42; export OVERWRITE=a; export | grep OVERWRITE
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OVERWRITE="a"
### minishell result: 
> 

---
# export OVERWRITE=42; export OVERWRITE=a; export | grep OVERWRITE
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export A=B=C=D; export | grep A
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x A="B=C=D"
> declare -x CPATH="/Users/hyoshie/.brew/opt/readline/include:"
> declare -x HOMEBREW_CACHE="/tmp/hyoshie/Homebrew/Caches"
> declare -x LESS_TERMCAP_mb="[01;34m"
> declare -x LESS_TERMCAP_md="[01;34m"
> declare -x LESS_TERMCAP_me="[0m"
> declare -x LESS_TERMCAP_se="[0m"
> declare -x LESS_TERMCAP_so="[01;44;33m"
> declare -x LESS_TERMCAP_ue="[0m"
> declare -x LESS_TERMCAP_us="[01;33m"
> declare -x LOGNAME="hyoshie"
> declare -x MAIL="hyoshie@student.42tokyo.jp"
> declare -x MAKEFLAGS=""
> declare -x MAKELEVEL="1"
> declare -x MANPATH="/Users/hyoshie/.brew/Cellar/readline/8.1.1/share/man:"
> declare -x MFLAGS=""
> declare -x PATH="/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki:/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/Users/hyoshie/.brew/opt/fzf/bin"
> declare -x SAVEHIST="100000"
> declare -x TERM_PROGRAM="tmux"
> declare -x TERM_PROGRAM_VERSION="3.2a"
> declare -x TMUX_PANE="%6"
### minishell result: 
> 

---
# export A=B=C=D; export | grep A
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export PATH; export | grep PATH
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x CPATH="/Users/hyoshie/.brew/opt/readline/include:"
> declare -x MANPATH="/Users/hyoshie/.brew/Cellar/readline/8.1.1/share/man:"
> declare -x PATH="/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki:/Users/hyoshie/.brew/opt/llvm/bin:/Users/hyoshie/.nodebrew/current/bin:/Users/hyoshie/.command:/Users/hyoshie/.brew/bin:/Users/hyoshie/.brew/opt/fzf/bin"
### minishell result: 
> 

---
# export PATH; export | grep PATH
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: export: 'PATH;': not a valid identifier

---
# export PATH; export | grep PATH
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD
> declare -x PWD="/Users/hyoshie/project/minish"
### minishell result: 
> 

---
# export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: export: 'PWD;': not a valid identifier

---
# export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD
### minishell result: 
> 

---
# export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: export: 'OLDPWD;': not a valid identifier

---
# export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# unset PWD; cd ..; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD=""
### minishell result: 
> 

---
# unset PWD; cd ..; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'PWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier

---
# unset PWD; cd ..; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# unset OLDPWD; cd ..; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
### minishell result: 
> 

---
# unset OLDPWD; cd ..; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'OLDPWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier

---
# unset PWD; cd ..; export PWD=new_value; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD=""
> declare -x PWD="new_value"
### minishell result: 
> 

---
# unset PWD; cd ..; export PWD=new_value; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'PWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier
> minishell: unset: 'PWD=new_value;': not a valid identifier

---
# unset PWD; cd ..; export PWD=new_value; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# unset OLDPWD; cd ..; export OLDPWD=new_value; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD="new_value"
### minishell result: 
> 

---
# unset OLDPWD; cd ..; export OLDPWD=new_value; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'OLDPWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier
> minishell: unset: 'OLDPWD=new_value;': not a valid identifier

---
# unset OLDPWD; cd ..; export OLDPWD=new_value; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# unset PWD; cd ..; export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD=""
> declare -x PWD="/Users/hyoshie/project"
### minishell result: 
> 

---
# unset PWD; cd ..; export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'PWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier
> minishell: unset: 'PWD;': not a valid identifier

---
# unset PWD; cd ..; export PWD; export | grep PWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# unset OLDPWD; cd ..; export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> declare -x OLDPWD="/Users/hyoshie/project/minish"
### minishell result: 
> 

---
# unset OLDPWD; cd ..; export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: unset: 'OLDPWD;': not a valid identifier
> minishell: unset: '..;': not a valid identifier
> minishell: unset: 'OLDPWD;': not a valid identifier

---
# unset OLDPWD; cd ..; export OLDPWD; export | grep OLDPWD
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 1

---
# export =
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
### minishell result: 
> 

---
# export =
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
> minishell: export: `=': not a valid identifier
### minishell result: 
> minishell: export: '=': not a valid identifier

---
