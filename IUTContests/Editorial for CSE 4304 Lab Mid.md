# Editorial for [CSE 4304: Data Structures Lab Mid Assessment](https://vjudge.net/contest/663232)

<details>
<summary>Problem A</summary>

The problem can be solved using a double-ended queue (deque) to manage elements from both ends. The size of the deque must be maintained so that it never exceeds a given limit $n$. If a push operation would cause the deque to exceed this limit, the operation is ignored, and "The queue is full" is output.

For implementation, an STL deque can be utilized to efficiently handle insertions and deletions from both the front and the back. Alternatively, a fixed-size array, such as one of size 200, can be used along with two pointers to simulate the deque behavior. Other structures, such as linked lists or circular arrays, may also be adapted to implement the deque.

</details>

<details>
<summary>Problem B</summary>

This problem can be solved in many ways but the intended solution is using two stacks to manage browsing history: `backward_stack` for the backward history and `forward_stack` for the forward history. Additionally, a variable `current_page` is used to track the currently visited page. Initially, `current_page` is set to "http://www.lightoj.com/". The process for each command is described below.

#### VISIT Command:

When the "VISIT" command is encountered, the `current_page` is pushed onto the `backward_stack` to store the current browsing state. The given URL is then assigned to `current_page`, representing the new page being visited. At the same time, the `forward_stack` is cleared since all forward history is lost when a new page is visited.

#### BACK Command:

For the "BACK" command, if the `backward_stack` is not empty, the `current_page` is pushed onto the `forward_stack` to store it for potential forward navigation. The top URL from the `backward_stack` is then popped and set as the new `current_page`, simulating moving back in the history. If `backward_stack` is empty, "Ignored" is output since there's no previous page to navigate to.

#### FORWARD Command:

When the "FORWARD" command is received, if the `forward_stack` is not empty, the `current_page` is pushed onto the `backward_stack`, and the top URL from the `forward_stack` is popped and assigned to `current_page`, representing a move forward in the browsing history. If `forward_stack` is empty, "Ignored" is output as there is no forward history to navigate to.

By managing the stacks in this manner, along with maintaining `current_page`, the browsing history is effectively simulated, and the correct outputs are produced for each operation.

</details>

<details>
<summary>Problem C</summary>

<details>
<summary>Hint 1</summary>

The employee-manager hierarchy can be represented with trees.

</details>

<details>
<summary>Hint 2</summary>

Let's call a person with no manager a supermanager (the root of a tree). Can any other member of the tree be in the same group as the supermanager?

</details>

<details>
<summary>Hint 3</summary>

Let's define the level of a node in a tree as its distance from the root. What is the relation between the level of an employee and his manager?

</details>

<details>
<summary>Solution</summary>

The scenario can be easily modeled using trees, where each employee is a node and each manager-employee relationship is an edge. Let's define a **supermanager** as an employee with no manager and is the root of his respective tree. The goal is to group employees such that no superior and subordinate are in the same group.

Here are some observations:

- A supermanager must be in a different group from all subordinates, as they are superior to everyone in their tree.
- Employees at the same level in a tree do not have direct superior-subordinate relationships, so it is best to group them together.
- In that case, employees at different levels in the same tree must be in separate groups.

With the observations, we can simply deduce that:

- Each supermanager forms the root of a tree. The number of levels (**height**) of that tree dictates the minimum number of groups needed for the employees in that tree.
- The minimum number of groups required for the entire company is equal to the maximum height among all the trees.

</details>
</details>

<details>
<summary>Problem D</summary>

This is an implementation problem. The solution is straightforward and involves the following steps:

#### Tree Construction:

The binary tree is constructed from the input provided in level-order, where each node may have left and right children. Missing children are indicated by `-1`.

#### Tree Traversal and Swap Operation:

For each query with a depth value \( k \):

- **Track Depth:** A tree traversal function is used, maintaining the current depth with a variable called `current_level`.
- **Identify Nodes:** During traversal, it is checked whether `current_level` is a multiple of \( k \). If so, the left and right children of that node are swapped.
- **Recursive Traversal:** The traversal continues for both left and right children, incrementing `current_level` as the traversal moves deeper into the tree.

#### Handling Multiple Queries:

The task involves executing multiple queries, and after each query, the **in-order traversal** of the modified tree must be output, which involves:

- Visiting the left subtree.
- Visiting the root node.
- Visiting the right subtree.

</details>

<details>
<summary>Problem E</summary>

<details>
<summary>Hint 1</summary>

The number of reorders is to be minimized. In a single reorder, as many swaps as necessary can be made.

</details>

<details>
<summary>Hint 2</summary>

How should the stack look after reordering?

</details>

<details>
<summary>Hint 3</summary>

What is the best time for performing the reorder?

</details>

<details>
<summary>Solution</summary>

### observations
Adding new boxes is trivial, we put it at the top of the pile(the word pile will be used to avoid confusion with the data structure: stack). Removing, however, needs some observation.

Lets analyze the simpler cases. 
1. The next number to be removed is on top of the pile: In that case we remove that.
2. The next number to be removed is NOT on top of the pile: In that case, we must rearrange.

As we want to minimize the numbers of rearrange operations, we should rearrange the pile in a smart way- that reduces the number of rearranges in future. 

Lets think of the case when we only have remove operations left. The best case here is when the pile is sorted, having the smallest number on top. In that case, we can remove all elements without needing to rearrange. This strategy will always work, because we will never remove a larger element before a smaller one.

The final observation is, if we insert a new element after the pile has been sorted, we cannot remove any sorted element because of the new element being on top; thus if needed, the pile needs to be sorted again.
### solution
We will maintain a stack of the numbers of boxes, which have been added after the pile was last sorted. A empty stack will represent the current pile is sorted.

- ADD: we push the new element to our stack.
- REMOVE:
    - if the stack is non-empty: We have added new elements after the last sort. So, we check if the top element of stack is the number to be removed or not.
    1. If it is: we pop from the stack and move on to next operation.
    2. If its not: The only option is to re-sort the pile again; so we clear the stack, and increase the result by one.
    - if the stack is empty: Means the pile is sorted in our favor; we move on to next operation.

</details>
</details>
