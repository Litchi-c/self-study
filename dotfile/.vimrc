colorscheme molokai
syntax enable

" CRAZY!!
noremap <Left> :echoe "Use h"<CR>
noremap <Right> :echoe "Use l"<CR>
noremap <Up> :echoe "Use k"<CR>
noremap <Down> :echoe "Use j"<CR>


" Use the Solarized Dark theme
" set background=dark
" colorscheme solarized
" let g:solarized_termtrans=1

" Make Vim more useful
set nocompatible

" Use the OS clipboard by default (on versions compiled with `+clipboard`)
set clipboard=unnamed

" Set line number and support mouse
set number
set relativenumber
set mouse=a

" Enhance command-line completion
set wildmenu
" Allow cursor keys in insert mode
set esckeys
" Allow backspace in insert mode
set backspace=indent,eol,start
" Optimize for fast terminal connections
set ttyfast
" Add the g flag to search/replace by default
set gdefault
" Use UTF-8 without BOM
set encoding=utf-8 nobomb

" editor
set nobackup
set noswapfile
set undofile
set undodir=~/.vim/.undo//
set noerrorbells
set history=1000

" Set syntax and  current line is highlight
syntax on
set cursorline

" Set tab
set expandtab
set tabstop=2
set shiftwidth=2

" Show “invisible” characters
set lcs=tab:▸\ ,trail:·,eol:¬,nbsp:_



set list
" Highlight searches
set hlsearch
" Ignore case of searches
set ignorecase
" Highlight dynamically as pattern is typed
set incsearch
" Always show status line
set laststatus=2
" set search
set smartcase

" Disable error bells
" set noerrorbells
nmap Q <Nop>
set noerrorbells visualbell t_vb=

" Don’t reset cursor to start of line when moving around.
set nostartofline
" Show the cursor position
set ruler
" Don’t show the intro message when starting Vim
set shortmess=atI
" Show the current mode
set showmode
" Show the filename in the window titlebar
set title
" Show the (partial) command as it’s being typed
set showcmd

autocmd BufRead,BufNewFile Makefile set noexpandtab

func SetTitleForPython()
call setline(1, "\#!/usr/bin/python3")
call setline(2, "\# -*- coding=utf8 -*-")
call setline(3, "\"\"\"")
call setline(4, "\# @Author : Sugar")
call setline(5, "\# @Created Time : ".strftime("%Y-%m-%d %H:%M:%S"))
call setline(6, "\# @Description :")
call setline(7, "\"\"\"")
normal G
normal o
endfunc
autocmd bufnewfile *.py call SetTitleForPython()


func SetTitleForCXX()
call setline(1, "// @Author : Sugar")
call setline(2, "// @Created Time : ".strftime("%Y-%m-%d %H:%M:%S"))
call setline(3, "// @Description :")
normal G
normal o
endfunc
autocmd bufnewfile *.{c,cxx,cc} call SetTitleForCXX()

func SetTitleForMainCPP()
call setline(1, "// @Author : Sugar")
call setline(2, "// @Created Time : ".strftime("%Y-%m-%d %H:%M:%S"))
call setline(3, "// @Description :")
call setline(4, "")
call setline(5, "#include <iostream>")
call setline(6, "using std::cin;")
call setline(7, "using std::cout;")
call setline(8, "")
call setline(9, "int main(int argc,char **argv){")
call setline(10, "    return 0;")
call setline(11, "}")
normal 9gg
normal o
endfunc
autocmd bufnewfile main.cpp call SetTitleForMainCPP()


func SetTitleForMakefile()
call setline(1, "CC=g++")
call setline(2, "CFLAGS=-g -Og")
call setline(3, ".PHONY:clean")
call setline(4, "clean:")
call setline(5,"	rm -rf *.o *.out")
normal G 
normal o
endfunc
autocmd bufnewfile Makefile call SetTitleForMakefile()
