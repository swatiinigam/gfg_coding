<h2><a href="https://www.geeksforgeeks.org/problems/minimize-cash-flow/0?sortBy=newest&query=page1sortBynewest">Minimize Cash Flow</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the friends is minimized.&nbsp;</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N=3<code>
</code>transaction <code>[][]={{0,100,0}, {0,0,100}, {100,0,0}}
<strong>Output:</strong>
</code>transaction <code>[][]={{0,0,0},{0,0,0},{0,0,0}}
<strong>Explanation:</strong>
</code>Since friend one has to give friend two which has to give friend three and which in turn has to give one. So it is better than no one will do anything to anyone.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N=3
transaction [][]={{0,100,0},{0,0,200},{0,0,0}}
<strong>Output:</strong>
transaction [][]={0,0,100},{0,0,100},{0,0,0}
<strong>Explanation:</strong>
The net flow is minimized.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>minCashFlow</strong><strong>()</strong> which takes the transaction array and number of friends as input parameters and returns the new transaction array as output;. Please note there can be multiple solutions possible, and the solution will be judged according to its net flow, and if it correctly follows the cash flow. If, you're solution returns -1, this means the cash flow is not following the actual flow of cash.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N*N)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N*N)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 1000<br>0<sup>&nbsp;</sup>&lt;= transaction[i][j] &lt;= 1000</span></p></div>