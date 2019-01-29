### asio
work 可以是的执行run的线程在执行完毕任务之后不会退出

post 将任务丢进任务队列, 任务会按照顺序的执行
dispatch 及时请求io_service处理任务

poll 处理执行完毕的任务的会调，没有执行完毕的任务则立即返回。

run 阻塞处理任务，直到任务处理完毕，如果没有任务则会立即返回。

stop 它仅仅只是给iocp发送一个退出消息而并不是等待其真正退出。因为poll和poll_one本来就不等待（GetQueuedCompletionStatus时timeout = 0）
所以此函数对poll和poll_one无意义。对于run_one来说，如果该事件还未完成，则run_one会立刻返回
如果该事件已经完成，并且还在处理中，则stop并无特殊意义（会等待handler完成后自然退出）
对于run来说，stop的调用会导致run中的 GetQueuedCompletionStatus立刻返回
并且由于设置了stopped = 1，此前完成的消息的handlers也不会被调用。

stop会导致所有未完成的消息以及完成了但尚未处理得消息都直接被丢弃，不会导致handlers调用