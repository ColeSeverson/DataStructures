using System;
using System.Collections.Generic;

namespace DataStructures {
    namespace Resources
    {
        public class Node<T>
        {
            public Node<T> Left{ get; set; }
            public Node<T> Right{ get; set; }
            public Node<T> Next{ get { return Left; } set { Left = value; } }
            public T Data{ get; set; }
            public Node(T data, Node<T> left=null, Node<T> right=null) {
                this.Data = data;
                this.Left = left;
                this.Right = right;
            }
        }
}
}
