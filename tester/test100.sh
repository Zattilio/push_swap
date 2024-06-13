#!/bin/bash

echo ""
echo "Test with 100 arguments"
# Génération de 100 nombres aléatoires compris entre 1 et 100
for i in {1..100}
do
  arguments=$(echo $(shuf -i 1-100 -n 100))
  output=$(./push_swap $arguments)
  lines=$(echo "$output" | wc -l)
  if [ $lines -gt 700 ]; then
	  echo "            KO $lines"
  else
	  echo "OK ($lines steps)"
  fi
  checker=$(./push_swap $arguments | ./checker $arguments)
  if [ "$checker" == "KO" ]; then
	  echo "            NON TRIE $checker"
	  echo $arguments
  fi
done

# Appel du programme "push_swap" avec les 100 nombres aléatoires en argument

