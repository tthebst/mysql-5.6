# How to build


## Download source code

```
git clone https://github.com/tthebst/mysql-5.6.git
cd mysql-5.6
git checkout fb-mysql-8.0.20-pmem
git submodule init
git submodule update

```

### Build boost

```
cd boost
./bootstrap.sh
./b2
```

## CMAKE

```
 cmake ../mysql-5.6/ -DCMAKE_BUILD_TYPE=RelWithDebInfo -DWITH_SSL=system -DWITH_ZLIB=bundled -DMYSQL_MAINTAINER_MODE=0 -DENABLED_LOCAL_INFILE=1 -DENABLE_DTRACE=0 -DCMAKE_CXX_FLAGS="-march=native" -DWITH_BOOST=../mysql-5.6/boost
```