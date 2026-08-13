for f in temp/*.in
do
  echo ----$f
  time ./books2 < $f
done
