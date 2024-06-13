#!/bin/bash

echo ""
echo "Test with 500 arguments"
# Génération de 100 nombres aléatoires compris entre 1 et 100
for i in {1..100}
do
  arguments=$(echo $(shuf -i 1-500 -n 500))
  output=$(./push_swap $arguments)
  lines=$(echo "$output" | wc -l)
  if [ $lines -gt 5500 ]; then
	  echo "            KO $lines"
  fi
  checker=$(./push_swap $arguments | ./checker $arguments)
  if [ "$checker" == "OK" ]; then
	  echo "OK ($lines steps)"
  else
	  echo "             ERROR TRIAGE $checker"
  fi
done

# Appel du programme "push_swap" avec les 100 nombres aléatoires en argument

