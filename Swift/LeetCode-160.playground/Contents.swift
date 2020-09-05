public class ListNode {
     public var val: Int
     public var next: ListNode?
     public init(_ val: Int) {
         self.val = val
         self.next = nil
     }
}

class Solution {
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        guard var p1 = headA, var p2 = headB else { return nil }
        var end1: Int? = nil
        var end2: Int? = nil
        while p1 !== p2 {
            if p1.next == nil {
                p1 = headB!
                end1 = p1.val
            }
            if p2.next == nil {
                p2 = headA!
                end2 = p2.val
            }
            p1 = p1.next!
            p2 = p2.next!
            if let end1 = end1, let end2 = end2, end1 != end2 { return nil }
        }
        return p1
    }
}
