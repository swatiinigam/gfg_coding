<h2><a href="https://www.geeksforgeeks.org/problems/path-of-greater-than-equal-to-k-length1034/1">Path of greater than equal to k length</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length <strong>greater than or equal to k</strong>,(without any cycle) starting from a given source and ending at any other vertex.<br>
Source vertex should always be&nbsp; 0.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
V = 4 , E = 3 and K = 8
A[] = [0, 1, 5, 1, 2, 1, 2, 3, 1]
<strong>Output:</strong>&nbsp;0
<strong>Explanation</strong>:
There exists no path which has a distance 
of 8. 
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
V = 9, E = 14 and K = 60
A[] = [0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 
11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 
3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 
8, 6, 7, 8, 7]
<strong>Output: </strong>0
<strong>Explanation:
</strong><img alt="" src="http://www.geeksforgeeks.org//wp-content/uploads/Fig-11.jpg" style="height:316px; width:677px">
 

</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>pathMoreThanK()</strong>&nbsp;which takes the integer V, Edges E, an integer K and Array A which is having (Source, Destination, Weight)&nbsp;as input parameters and returns 1 if the path of at least k distance exists, else returns 0.<br>
<br>
<strong>Expected Time Complexity:</strong> O(N!)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p style="text-align:justify">&nbsp;</p>

<p style="text-align:justify"><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ V ≤ 5<br>
1 ≤ E ≤ 20<br>
1 ≤ K ≤ 100</span></p>
</div>