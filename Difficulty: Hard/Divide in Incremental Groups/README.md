<h2><a href="https://www.geeksforgeeks.org/problems/divide-in-incremental-groups--170647/1?page=2&difficulty=Hard&status=unsolved&sortBy=submissions">Divide in Incremental Groups</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two integers <strong>N</strong> and <strong>K</strong>, the task is to count the number of ways to divide <strong>N</strong> into groups of <strong>positive integers</strong>. Such that <strong>each group</strong> shall have <strong>K elements</strong> and their <strong>sum is N</strong>. Also the number of elements in the groups follows a <strong>non-decreasing</strong> order <strong>(i.e. group[i] &lt;= group[i+1])</strong>. Find the number of such groups</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 8
K = 4
<strong>Output:</strong>
5
<strong>Explanation:</strong>
There are 5 groups such that their sum is 8 
and the number of positive integers in each 
group is 4.&nbsp;The 5 groups are [1, 1, 1, 5], 
[1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3] and 
[2, 2, 2, 2].</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
N = 4
K = 3
<strong>Output:</strong>
1
<strong>Explanation: </strong>
The only possible grouping is {1, 1, 2}. Hence,</span>
<span style="font-size:18px">the answer is 1 in this case.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete the function <strong>countWaystoDivide</strong><strong>() </strong>which takes the integers&nbsp;<strong>N</strong>&nbsp;and <strong>K&nbsp;</strong>as the input parameters, and returns the number of ways to divide the sum <strong>N </strong>into<strong> K&nbsp;</strong>groups.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N<sup>2</sup>*K)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N<sup>2</sup></span><span style="font-size:18px">*K)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ K ≤&nbsp;N ≤ 100</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Expedia</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;