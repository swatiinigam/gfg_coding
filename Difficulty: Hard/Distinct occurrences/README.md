<h2><a href="https://www.geeksforgeeks.org/problems/distinct-occurrences/1?page=2&difficulty=Hard&sortBy=submissions">Distinct occurrences</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given two strings, <strong><code>txt</code></strong> and <strong><code>pat</code></strong>, find the count of distinct occurrences of <code>pat</code> as a subsequence in <code>txt</code>.</span></p>
<p><span style="font-size: 14pt;"><strong>Note:</strong> It is guaranteed that the output will fit within 31 bits.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>txt = "banana" , pat = "ban"
<strong>Output:</strong> 3
<strong>Explanation</strong>: There are 3 sub-sequences:[ban], [ba n], [b an].
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: txt = "geeksforgeeks" , pat = "ge"
<strong>Output:</strong> 6
<strong>Explanation</strong>: There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: txt = "aabbcc" , pat = "abc"
<strong>Output: </strong>8
<strong>Explanation</strong>: There are 8 distinct subsequences: [a b c], [a b c], [a b c], [a b c], [a b c], [a b c], [a b c], [a b c].</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ txt.length(), pat.length() ≤ 10<sup>3</sup><br>Both <code>txt</code> and <code>pat</code> contain only lowercase alphabets.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;