/**
     * 递归方法：调用自身进行比较合并，消耗内存。
     * @param head1
     * @param head2
     * @return
     */
    public ListNode merge(ListNode head1, ListNode head2) {
        // head1为空，返回head2
        if(head1 == null) return head2;
        // head2为空，返回head1
        if(head2 == null) return head1;
        // 记录合并链表
        ListNode node = null;
        if(head1.value > head2.value) {
            node = head2;
            node.next = merge(head1, head2.next);
        } else {
            node = head1;
            node.next = merge(head1.next, head2);
        }
        return node;
    }
    
    /**
     * 非递归方法：消耗内存少。
     * @param head1
     * @param head2
     * @return
     */
    public ListNode merge1(ListNode head1, ListNode head2) {
        // head1为空，返回head2
        if(head1 == null) return head2;
        // head2为空，返回head1
        if(head2 == null) return head1;
        // 记录合并链表
        ListNode tempNode = new ListNode(-1);   
        // 指向合并链表的尾结点
        ListNode node = tempNode;
        
        // 两链表都不为空进行比较合并 
        while(head1 !=null && head2 !=null) {
            if(head1.value < head2.value) {   
                node.next = head1;
                head1 = head1.next;
            } else {
                node.next = head2;
                head2 = head2.next;
            }
            node = node.next; // 将指针移动到合并后链表的结尾，方便下次
        }
        // 如果第一个链表的元素未处理完，将其接到合并链表的最后一个结点之后
        if(head1 != null) {
            node.next = head1;
        }
        
        // 如果第二个链表的元素未处理完，将其接到合并链表的最后一个结点之后
        if(head2 != null) {
            node.next = head2;
        }
        return tempNode.next;  
    }
