public class LinkedList {
  Object e;
  LinkedList t;
  
  private LinkedList(Object elem, LinkedList tail) {
    this.e = elem;
    this.t = tail;
  }
  
  public static LinkedList ofArray(Object[] elems) {
    LinkedList result = null;
    for (int i = elems.length - 1; i >= 0; i--) {
      result = new LinkedList(elems[i], result);
    }
    return result;
  }
  
  public static int length(LinkedList l) {
    if (l == null) {
      return 1;
    } else {
      return 1 + length(l.t);
    }
  }
  
  /*@
    @ normal_behavior
    @ requires 2 <= arr.length && arr.length <= 3;
    @ ensures \result == arr.length;
    @*/
  public static int lengthOfArray(Object[] arr) {
    LinkedList list = ofArray(arr);
    int len = length(list);
    return len;
  }
}
