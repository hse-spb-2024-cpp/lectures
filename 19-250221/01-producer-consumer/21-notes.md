# Важное про condition variable
* `wait()` — это оптимизация. Если её заменить на "отпустили мьютекс,
  подождали, взяли мьютекс обратно", то всё ещё должно работать.
* Следствие: condition variable никогда не используются без какого-то отслеживаемого условия или мьютекса.

# Мораль
* Никогда не модифицируйте ничего без мьютекса!
  Даже если сейчас не стреляет, ловить потом будет сложно.
* Не надо брать мьютекс надолго.
* Обычно проще писать не через condvar'ы, а через future или каналы (потокобезопасная очередь сообщений).
  * Но ещё лучше вообще писать без потоков или хотя бы не синхронизировать ничего руками.

#
notify() is better be under mutex:
https://sourceware.org/git/?p=valgrind.git;a=blob;f=helgrind/hg_main.c;h=490fc38fefc7fd6e241ab8c592edb428933c90f4;hb=HEAD#l2421
https://en.cppreference.com/w/cpp/thread/condition_variable/notify_one#Notes
https://cplusplus.github.io/LWG/issue3343
https://github.com/isocpp/CppCoreGuidelines/issues/1272
https://github.com/isocpp/CppCoreGuidelines/issues/554#issuecomment-425687510
