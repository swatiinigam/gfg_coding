<h2><a href="https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Delete a node from BST</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Search Tree and a node value x</span><span style="font-size: 18px;">. Delete the node with the given value x from the BST. If no node with value x exists, then do not make any change.&nbsp;</span><span style="font-size: 18px;">Return the root of the BST after deleting the node with value x. Do not make any update if there's no node with value x present in the BST.</span></p>
<p><strong style="font-size: 18px;">Note:&nbsp;</strong><span style="font-size: 18px;">The generated output will be the inorder traversal of the modified tree.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>      2
&nbsp;   /   \
&nbsp;  1     3
x = 12
<strong>Output: </strong>1 2 3<strong>
Explanation: </strong>In the given input there is no node with value 12 , so the tree will remain same.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;\
 &nbsp; &nbsp;    &nbsp; &nbsp; &nbsp; 2
 &nbsp; &nbsp;&nbsp; &nbsp;       &nbsp;&nbsp;\
 &nbsp; &nbsp; &nbsp;        &nbsp;  8 
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; &nbsp; \
 &nbsp; &nbsp; &nbsp; &nbsp;     &nbsp;5&nbsp;  &nbsp;  11
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; \&nbsp; &nbsp; /  \
 &nbsp; &nbsp; &nbsp;     4 &nbsp; &nbsp;7&nbsp; 9 &nbsp;&nbsp;12
x = 9
<strong>Output: </strong>1 2 4 5 7 8 11 12<strong>
Explanation: </strong>In the given input tree after deleting 9 will be
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  1
&nbsp; &nbsp; &nbsp; &nbsp;   &nbsp; &nbsp;&nbsp;\
&nbsp; &nbsp;     &nbsp;  &nbsp; &nbsp; 2
&nbsp; &nbsp;&nbsp; &nbsp;        &nbsp; &nbsp;\
&nbsp; &nbsp; &nbsp;        &nbsp;  &nbsp; 8
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;  &nbsp;/&nbsp;  \
&nbsp; &nbsp; &nbsp; &nbsp;        &nbsp;5&nbsp; &nbsp;  11
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; /&nbsp; \&nbsp; &nbsp; &nbsp;\
&nbsp; &nbsp; &nbsp;         4 &nbsp; &nbsp;7&nbsp; &nbsp;&nbsp;&nbsp;12</span>&nbsp;</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(Height of the BST).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the BST).</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Samsung</code>&nbsp;<code>Adobe</code>&nbsp;<code>Qualcomm</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Data Structures</code>&nbsp;