# super-nuko-world
2016.05.26 信息组测试

## Contest materials

#### problems/
题目描述的 PDF 文件。

#### problems/tex/
生成 PDF 文件的 LaTeX 源文件和图像。
```bash
    $ xelatex *.tex
```

#### data/
测试数据（ZIP）。文件命名格式为 `<Subtask%d>-<Testcase%02d>.[in|out]`
（例如第一个子任务的第三个测试点命名为 `1-03.[in|out]`）。

#### data/*-gen/
用于生成测试数据的程序。直接编译运行即可。

#### checkers/
Special Judge 程序。按照 CMS 的文档，在服务器上使用下列命令编译：
```bash
    $ g++ -o nekojyarashi-checker nekojyarashi-checker.cpp -static
    $ g++ -o hako-checker hako-checker.cpp -static
    $ scp root@xx.xx.xx.xx:/path/to/checker/*-checker .
```

#### std/
（一点也不标准的）参考程序。C++/Pascal。

## Original problems
* __1. Ofuton__:
    USACO 2016 US Open Contest, Gold  
    [Problem 1. Splitting the Field](http://usaco.org/index.php?page=viewproblem2&cpid=645)  
    在线测评：BZOJ 4578

* __2. Matatabi__:
    JOI 2013/2014 春季集训  
    [Day 2 有趣的家庭菜园（たのしい家庭菜園）](https://www.ioi-jp.org/camp/2014/2014-sp-tasks/index.html)  
    附[出题人题解](https://www.ioi-jp.org/camp/2014/2014-sp-tasks/2014-sp-d1-growing-review.pdf)  
    在线测评：BZOJ 4240

* __3. Nekojyarashi__:
    Codeforces Round #311 (Div. 2)  
    [D. Vitaly and Cycle](http://codeforces.com/contest/557/problem/D)  
    [出题人题解](http://codeforces.com/blog/entry/18943)  
    在线测评：Codeforces 557D

* __4. Hako__:
    自己 YY 的= =

所有题目名称 & 题面来源于 Vocaloid 曲『すーぱーぬこわーるど（超级喵世界）』（词曲：まふまふ，Vocal：IA feat. 鏡音リン）  
[Original / Niconico](http://www.nicovideo.jp/watch/sm22491239) [Bilibili](http://www.bilibili.com/video/av879378/)  
[Cover by ゆいこんぬ＆あやぽんず＊ / Niconico](http://www.nicovideo.jp/watch/sm22944873) [Bilibili](http://www.bilibili.com/video/av978370/)  
[osu!](https://osu.ppy.sh/s/153776)  

## The server
阿里云 ECS / 华北 1 / 1 核 CPU / 1024 MB RAM / CentOS 7.0 64-bit / 1 Mbps

测评系统：[Contest Management System](http://cms-dev.github.io/) 1.2.0 / Python 3.6.0a1 / PIP 7.1.0

```bash
    $ pip list
    backports-abc (0.4)
    backports.ssl-match-hostname (3.4.0.2)
    BeautifulSoup (3.2.1)
    certifi (2016.2.28)
    chardet (2.0.1)
    cms (1.2.0)
    configobj (4.7.2)
    coverage (4.0.3)
    decorator (3.4.0)
    funcsigs (1.0.2)
    gevent (1.1.1)
    greenlet (0.4.9)
    iniparse (0.4)
    kitchen (1.1.1)
    langtable (0.0.13)
    mechanize (0.2.5)
    mock (2.0.0)
    netifaces (0.10.4)
    patool (1.12)
    pbr (1.9.1)
    pip (7.1.0)
    psutil (0.6.1)
    psycopg2 (2.6.1)
    pycrypto (2.6.1)
    pycurl (7.19.0)
    pygobject (3.8.2)
    pygpgme (0.3)
    pyliblzma (0.5.3)
    python-augeas (0.4.1)
    pytz (2016.4)
    pyudev (0.15)
    pyxattr (0.5.1)
    PyYAML (3.11)
    requests (2.10.0)
    setuptools (21.1.0)
    singledispatch (3.4.0.3)
    six (1.10.0)
    slip (0.4.0)
    slip.dbus (0.4.0)
    SQLAlchemy (0.7.8)
    tornado (3.1.1)
    urlgrabber (3.10)
    Werkzeug (0.11.9)
    yum-langpacks (0.4.2)
    yum-metadata-parser (1.1.4)
```

## Acknowledgements
所有题目、部分数据和图片版权归原作者所有。  
题面描述和其余数据在 [CC BY International 4.0](https://creativecommons.org/licenses/by/4.0/) 下发布。  
源码在 [MIT/Expat](./LICENSE) 下发布。

感谢 [@yesterday17](https://github.com/yesterday17) 同学的测评服务器。

感谢大家的参与 =u=

