# mandelbrot1
マンデルブロ集合の描画

mandelbrot.cppにてマンデルブロ集合の座標データをdata/ディレクトリに出力します. フォーカスしたい点(x,y)とフォーカス速度, フレーム数を決め, data/ディレクトリに出力します. 
mandelbrot.pltにて, data/ディレクトリのデータをGif動画に描画します. 

コマンド
icpc -std=c++11 -O2 -ifort mandelbrot.cpp
./a.out
gnuplot mandelbrot.plt
