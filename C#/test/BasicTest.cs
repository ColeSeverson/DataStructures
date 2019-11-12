using System;
using Xunit;
using DataStructures.Basic;

namespace test
{
    public class LinkedListTest
    {
        [Fact]
        public void LinkedList1()
        {
            LinkedList<int> ll = new LinkedList<int>();
            ll.Insert(1);
            ll.Insert(2);
            ll.Insert(3);

            Assert.Equal(3, ll.Length); 
 
            LinkedList<int> llr = new LinkedList<int>();
            llr.Insert(3);
            llr.Insert(2);
            llr.Insert(1);
            
            ll.Reverse();
        }
    }
}
