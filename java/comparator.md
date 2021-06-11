# Comparator

*(Source: https://stackoverflow.com/questions/6478515/return-type-from-a-comparator/6478538)*

If the default behavior of a sorting algorithm based on the return value of a comparator is:

    -1 : does not swap
     0 : does not swap
    +1 : swap

And the default behavior of the return value of a comparator is:
  
    -1 : o1 < o2
     0 : o1 == o2 
    +1 : o1 > o2

We can change the implementation of a comparator as follow to sort descendingly. 

    -1 : o1 > o2
     0 : o1 == o2 
    +1 : o1 < o2
