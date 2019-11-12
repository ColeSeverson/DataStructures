using System;
using DataStructures;

namespace Build
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList<int> ll = new LinkedList<int>();
            ll.Insert(1);
            ll.Insert(2);
            ll.Insert(3);

            Console.WriteLine(ll.ToString());
            ll.Reverse();
            Console.WriteLine(ll.ToString());

            ll.Delete(2);
            Console.WriteLine($"{ll.Length}");
            Console.WriteLine($"{ll[1]} at index 1 in {ll.ToString()}");

            BinaryTree<int> bt = new BinaryTree<int>((a, b) => a - b);
            bt.Insert(10);
            bt.Insert(11);
            bt.Insert(9);
            bt.Insert(5);
            bt.Insert(7);
            bt.Insert(6);
            bt.Insert(3);
            bt.Insert(4);
            bt.Insert(5);

            bt.Print();

            bt.Delete(5);

            bt.Print();

            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }
    }
}
