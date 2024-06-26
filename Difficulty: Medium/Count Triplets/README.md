<h2><a href="https://www.geeksforgeeks.org/problems/count-triplets--141631/1">Count Triplets</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a sorted linked list&nbsp;of <strong>distinct</strong> nodes (no two nodes have the same data) and an integer <strong>X</strong>. Count <strong>distinct </strong>triplets in the list that sum up to given integer <strong>X</strong>.<br><br><strong>Note:</strong> The Linked List is sorted in descending order.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><strong><span style="font-size: 18px;">Input: </span></strong><span style="font-size: 18px;">LinkedList:</span> <span style="font-size: 18px;">9-&gt;8-&gt;6-&gt;5-&gt;4-&gt;2-&gt;1,  X = 17
<strong>Output:</strong> 2
<strong>Explanation:</strong> Distinct triplets are (2, 6, 9) 
and (4, 5, 8)&nbsp;which have sum equal to&nbsp;X i.e 17.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>LinkedList:</span> <span style="font-size: 14pt;">9-&gt;8-&gt;6-&gt;5-&gt;4-&gt;2-&gt;1</span>, <span style="font-size: 14pt;">X = 15</span><br><span style="font-size: 18px;"><strong>Output:</strong> 5
<strong>Explanation:</strong> (1, 5, 9), (1, 6, 8), (2, 4, 9), 
(2, 5, 8), (4, 5, 6) are the distinct triplets
</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task: </strong>&nbsp;<br>You don't need to read input or print anything. Complete the function <strong>countTriplets()</strong> which takes a head reference and X</span> <span style="font-size: 18px;">as input parameters and returns the triplet count.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>)<br><strong>Expected Auxiliary Space:</strong> O(N)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ Number of Nodes ≤ 10<sup>3</sup>&nbsp;<br>1 ≤ Node value&nbsp;≤ 10<sup>4</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;