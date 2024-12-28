<h2><a href="https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1?page=2&status=unsolved&sortBy=submissions">Total Decoding Messages</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">A top secret message containing letters <code>&nbsp;A-Z </code>is being encoded to numbers using the following mapping:</span></p>
<div class="highlighter-rouge">
<blockquote>
<p><span style="font-size: 14pt;">'A' -&gt; 1 <br></span><span style="font-size: 14pt;">'B' -&gt; 2 <br>... <br>'Z' -&gt; 26 </span></p>
</blockquote>
</div>
<p><span style="font-size: 14pt;">You are an FBI agent. You have to determine the total number of ways that message can be decoded.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s = "123"
<strong>Output: </strong>3
<strong>Explanation: </strong>"123" can be decoded as "ABC"(123), "LC"(12 3) and "AW"(1 23).
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s = "90"
<strong>Output: </strong>0
<strong>Explanation: </strong>"90" cannot be decoded as it's an invalid string and we cannot decode '0'.<sup><br></sup></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s = "05"
<strong>Output: </strong>0
<strong>Explanation: </strong>"05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding, so return 0.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 &lt;= s.size() &lt;= 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Flipkart</code>&nbsp;<code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Nutanix</code>&nbsp;<code>Linkedin</code>&nbsp;<code>Facebook</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;