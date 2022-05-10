If we observe the dictionary as described in the problem statement, we can easily find a pattern such that, for all possible strings ![](https://latex.codecogs.com/svg.image?s) where ![](https://latex.codecogs.com/svg.image?s_{0}&space;=&space;s_{1}), then the string is not included in the dictionary. Thus for each of the 26 letters in 
S<sub>0</sub> we get 25 letters in S<sub>1</sub> which makes the total count of words in the dictionary ![](https://latex.codecogs.com/svg.image?25&space;\times&space;26&space;=&space;650).</br>
Let our given string is ![](https://latex.codecogs.com/svg.image?s). So, there are already 25 words for each letters ![](https://latex.codecogs.com/svg.image?a,b,c,...,s_{0}). 
So here, we will get ![](https://latex.codecogs.com/svg.image?25\times(\textit{no.&space;of&space;letters&space;before&space;}s_0)).</br>And for the ![](https://latex.codecogs.com/svg.image?s_1)
 the serial of ![](https://latex.codecogs.com/svg.image?s_1) is added considering the position of ![](https://latex.codecogs.com/svg.image?s_1) and 
![](https://latex.codecogs.com/svg.image?s_0).
