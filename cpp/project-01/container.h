#ifndef __CONTAINER_H__
#define __CONTAINER_H__

class Container {
public:
  virtual void insert(int x) = 0;
  virtual int remove() = 0;
  virtual bool empty() const = 0;
  virtual ~Container();
};

#endif