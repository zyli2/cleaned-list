
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in MP3.1
    ListNode* position_;
    int count = 0;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }
    ListIterator(ListNode* position, int val): position_(position), count(val) {}


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in MP3.1
        if (position_->next == NULL) {
            ++count;
            position_ = NULL;
            return *this;
        }
        ListNode* temp = position_;
        position_ = temp->next;
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        // @TODO: graded in MP3.1
        ListNode* temp = position_;
        if (position_->next == NULL) {
            ++count;
            position_ = NULL;
            return ListIterator(temp);
        }
        position_ = temp->next;
        return ListIterator(temp);
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        ListNode* temp = position_;
        position_ = position_->prev;
        --count;
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        ListNode* temp = position_;
        position_ = position_->prev;
        --count;
        return ListIterator(temp);
    }

    bool operator!=(const ListIterator& rhs) {
        return (count != rhs.count);
    }

    bool operator==(const ListIterator& rhs) {
        return !(count != rhs.count);
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
