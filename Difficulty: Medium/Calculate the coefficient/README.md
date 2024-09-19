<h2><a href="https://www.geeksforgeeks.org/problems/calculate-the-coefficient/0">Calculate the coefficient</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two integers <strong>n</strong> and <strong>k,</strong> The task is to calculate Permutation Coefficient P(n,k).<br><strong>Note:&nbsp; </strong>P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements. <strong>Since this value may be large only find it modulo 10^9 + 7.</strong></span></p>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 10, k = 2
<strong>Output:</strong> 90
<strong>Explanation:</strong> <samp><code>For first case: Ans = 10! / (10 - 2)! = 10! / 8! , 10! is 8!*9*10 and 8! is 8!, Ans = 9*10 = 90.</code></samp></span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 10, k = 3
<strong>Output:</strong> 720</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(n)<br><strong>Expected Space Complexity:&nbsp;</strong>O(1)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 100000<br>0 </span><span style="font-size: 18px;">≤ k&nbsp;</span><span style="font-size: 18px;">≤ n</span></p></div>