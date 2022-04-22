" Reference:
" 1. https://github.com/anishathalye/dotfiles/blob/master/vimrc

" set colorscheme
syntax enable
colorscheme molokai
set background=dark
set nocompatible " not vi compatible

"------------------
" keyborad map
"------------------

" unbind keys
" C-A add count
" C-X sub conut
map <C-z> <Nop>  " C-Z and ZZ are very close!!! 'fg %1', i hate it.
map <C-s> <Nop>  " same as C-Z,due to I usually use word writing.
map <C-b> <Nop> " To use Tmux.
nmap Q <Nop>

" CRAZY!!!!
nnoremap <Left>  :echoe "Use h"<CR>
nnoremap <Right> :echoe "Use l"<CR>
nnoremap <Up>    :echoe "Use k"<CR>
nnoremap <Down>  :echoe "Use j"<CR>

" ...and in insert mode
inoremap <Left>  <ESC>:echoe "Use h"<CR>
inoremap <Right> <ESC>:echoe "Use l"<CR>
inoremap <Up>    <ESC>:echoe "Use k"<CR>
inoremap <Down>  <ESC>:echoe "Use j"<CR>

" quicker window movement
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-h> <C-w>h
nnoremap <C-l> <C-w>l

"------------------
" Syntax and indent
"------------------

syntax on     " turn on syntax highlighting
set showmatch " show matching braces when text indicator is over them

" highlight current line, but only in active window
augroup CursorLineOnlyInActiveWindow
    autocmd!
    autocmd VimEnter,WinEnter,BufWinEnter * setlocal cursorline
    autocmd WinLeave * setlocal nocursorline
augroup END

" use 2 spaces instead of tabs during formatting
set expandtab
set tabstop=2
set shiftwidth=2
set softtabstop=2

" using TAB in Makefile
autocmd BufRead,BufNewFile Makefile set noexpandtab 

"---------------------
" Basic editing config
"---------------------
set shortmess+=I  " disable startup message
set nu            " number lines
set rnu           " relative line numbering
set incsearch     " incremental search (as string is being typed)
set hls           " highlight search

" set list to see tabs and non-breakable spaces
" Show “invisible” characters
set lcs=tab:>>,trail:·,eol:¬,nbsp:~

" disable audible bell
set noerrorbells visualbell t_vb=

set lbr           " line break
set scrolloff=5   " show lines above and below cursor (when possible)
set laststatus=2
set backspace=indent,eol,start " allow backspacing over everything
set timeout timeoutlen=1000 ttimeoutlen=100 " fix slow O inserts
set lazyredraw    " skip redrawing screen in some cases

" automatically set current directory to directory of last opened file
set autochdir     
set hidden        " allow auto-hiding of edited buffers
set history=8192  " more history
set nojoinspaces  " suppress inserting two spaces between sentences
set nobackup      " 设置取消备份，禁止临时文件生成  
set noswapfile  

" smart case-sensitive search
set ignorecase
set smartcase
" tab completion for files/bufferss
set wildmode=longest,list
set wildmenu
set mouse+=a " enable mouse mode (scrolling, selection, etc)

" Use the OS clipboard by default (on versions compiled with `+clipboard`)
set clipboard=unnamed

"---------------------
" Plugin configuration
"---------------------
call plug#begin()
  Plug 'preservim/nerdtree'
  Plug 'itchyny/lightline.vim'
call plug#end()

" NerdTree set of keyboard map.

" Start NERDTree and leave the cursor in it.
" autocmd VimEnter * NERDTree
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>

" is unnecessary anymore
" because the mode information is displayed in the statusline.
set noshowmode      