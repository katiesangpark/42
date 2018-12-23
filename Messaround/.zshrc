# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/Users/kicausse/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="robbyrussell"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"
# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
  git
)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/rsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

listfiles() {
	ls -ump $1 | cat | tr "\n" "@" | rev | cut -c2- | rev | sed "s/@/\\\@/g" | tr "@" "\n" | tr -d ","
}

function inlineasm() {
	export norm="-1"
	export count="$#"
	export idx=0
	for var in "$@"
	do
		if [[ $var == "-norm"* ]]
		then
			export norm=$(echo $var | tr -d '-' | sed -E "s/[a-z]+//g")
			if [[ $norm == "" ]]
			then
				$norm = 60
			fi
			export count="$(echo $count'-1' | bc)"
		fi
	done
	if [[ $norm == -1 ]]
	then
		export norm=80
	fi
	for var in "$@"
	do
		if [[ $var == *".s" ]] 
		then
			if [ "$idx" -eq 1 ]; then
				echo ""
			fi
			export idx="$(echo $idx'+1' | bc)"
			if [ "$count" -ne 1 ]; then
				echo "$var:"
			fi
			if [[ $norm == 0 ]]
			then
				cat $var | tr -s "\n" | tr "\n" ";" | tr "\t" " " | tr -s " " | sed -E "s/.globl[ _a-z]+;([_a-z]+:;)?//g" | sed "s/; /;/g" | sed "s/ ;/;/g" | sed "s/ret;//g" | sed "s/:;/:/g" | perl -pe 's/(0x)?[0-9a-f]{5,}/hex $&/ge' |  tr -s "\n"
			else
				export tmp=$(echo "....asm(\""$(cat $var | tr -s "\n" | tr "\n" ";")"\");" | tr "\t" " " |  tr -s " " |  sed -E "s/ ?\+ ?/\+/g" | sed -E "s/ ?, ?/,/g" | sed -E "s/.globl[ _a-z]+;([_a-z]+:;)?//g" | sed "s/; /;/g" | sed "s/ ;/;/g" | sed "s/ret;//g" | sed "s/:;/:/g" | perl -pe 's/(0x)?[0-9a-fA-F]{5,}/hex $&/ge' |  tr -s "\n" | sed -e "s/.\{$(echo $norm"-1" | bc)\}[; ,:+\[]/&\@/g" | sed "s/@/\\\@/g" | tr "@" "\n" | sed "s/\.\.\.\./    /")
				export labels="$(echo $tmp | grep -Eo '[_0-9a-zA-Z]+:' | tr -d ':')"
				export	labelidx=0
				echo $labels |
				while IFS= read -r label;
				do
					export tmp=$(echo $tmp | sed "s/$label:/_$labelidx:/g" | sed "s/$label;/_$labelidx;/g")
					export labelidx="$(echo $labelidx'+1' | xargs echo "ibase=10; obase=16;" | bc)"
				done
				echo $tmp
			fi
		fi
	done
}

alias subl="~/Desktop/Sublime\ Text\ 2.app/Contents/SharedSupport/bin/subl"
alias Projects="/Users/kicausse/Desktop/Projects"
alias jpegtran="/sgoinfre/goinfre/Perso/kicausse/jpegtran"
alias py="/sgoinfre/goinfre/Perso/kicausse/Python365"
alias listallfiles='ls -ump *.c | cat | tr "\n" "@" | rev | cut -c2- | rev | sed "s/@/ \\\@/g" | tr "@" "\n" | tr -d ","'
alias listallfiles2='ls -umpR */*.c | cat | tr "\n" "@" | rev | cut -c2- | rev | sed "s/@/ \\\@/g" | tr "@" "\n" | tr -d ","'