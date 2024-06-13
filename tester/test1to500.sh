
echo ""
echo "Test with from 1 arguments to 500 arguments"

for i in $(seq 1 500)
do
  arguments=$(echo $(shuf -i 1-500 -n $i))
  output=$(./push_swap $arguments)
  lines=$(echo "$output" | wc -l)
  if [ $lines -gt 5500 ]; then
	  echo "KO $lines $i"
  fi
  checker=$(./push_swap $arguments | ./checker $arguments)
  if [ "$checker" != "OK" ]; then
	  echo "NON TRIE $checker $arguments"
  else
    echo "OK with $i arguments"
  fi
done
