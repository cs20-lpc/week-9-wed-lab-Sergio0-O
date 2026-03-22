template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    if (i <= 0) {
        throw string("Error: queue size must be greater than 0.");
    }

    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] buffer;
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("Error: queue is empty.");
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("Error: cannot dequeue from an empty queue.");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length = this->length - 1;

    if (this->length == 0) {
        frontIndex = 0;
        backIndex = -1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw string("Error: queue is full.");
    }

    if (isEmpty()) {
        frontIndex = 0;
        backIndex = 0;
        buffer[backIndex] = elem;
        this->length = 1;
    }
    else {
        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = elem;
        this->length = this->length + 1;
    }
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("Error: queue is empty.");
    }

    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}


template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}


template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}


template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
