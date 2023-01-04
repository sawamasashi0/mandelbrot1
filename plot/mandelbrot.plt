reset
#set terminal postscript enhanced
#set terminal postscript eps color lw 1.0 enhanced 30 size 10in, 8in
#set output "~/colloid/figures/mandelbrot.eps"
set term gif enhanced animate optimize size 500, 500
set output "../figures/mandelbrot.gif"
#set tics font "Times-Roman,33"   # 目盛りのフォントの変更
#set ylabel font "Times-Roman,33" # ylabelのフォントの変更
#set xlabel font "Times-Roman,33" # xlabelのフォントの変更
set bmargin 0
set lmargin 0
set rmargin 0
set tmargin 0
#set key right top
#set logscale xy
#set size 0.95, 1.0
#set key font "Times-Roman,24"
set size ratio -1
#set xtics rotate by 270
unset border
set xtics nomirror
set ytics nomirror
set format x "" 
set format y "" 
unset colorbox
#set xrange[-2:1.5]
#set yrange[-1.5:1.5]
load "gnuplot-palettes-master/blues.pal"
#load "gnuplot-palettes-master/greys.pal"
#p "/nfs/home/masashi/colloid/data/2020.07.15/mandelbrot.dat" u 1:2:3 w p pt 5 lc palette notitle
do for[i=1:100]{
    filename =sprintf('../data/man_%03d.dat', i)
    set xrange[-4*0.96**i/2-0.109293575:4*0.96**i/2-0.109293575]
    set yrange[-4*0.96**i/2+0.895245185:4*0.96**i/2+0.895245185] 
    p filename u 1:2:3 w p pt 5 lc palette notitle
}
set out
reset
    #p "/nfs/home/masashi/colloid/data/2020.07.15/man_005.dat" u 1:2:3 w p pt 5 lc palette notitle
