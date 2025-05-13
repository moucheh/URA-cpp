#pragma once

namespace ura {

template <typename It, typename E>
It find(It begin, It end, E element) {
  for (It temp = begin; temp != end; ++temp)
    if (*temp == element)
      return temp;
  return end;
}

template <typename It, typename P>
It find_if(It begin, It end, P fn) {
  for (It temp = begin; temp != end; ++temp)
    if (fn(*temp))
      return temp;
  return end;
}

// lower bound
template <typename It, typename E>
It binary_search(It begin, It end, E element) {
  auto pravi_end = end;
  auto n = end - begin;
  while (n != 0) {
    auto middle = begin + n / 2;
    if (*middle == element) {
      return middle;
    } else if (*middle < element) {
      begin = middle + 1;
    } else /* if (*middle > element) */ {
      end = middle;
    }
    n = end - begin;
  }
  return pravi_end;
}

} // namespace ura
