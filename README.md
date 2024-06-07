# Linux高级编程

## GitHub与Git

### 	关键字查询

​		1）awesome：去此标签类别中查找很酷的项目

​		2）tutorial：查询资料、书籍、文档

​		3）sample：查询对应技术的代码样本

### 	github三要素

​		1）Repository：仓库

​		定义：仓库是github项目管理存储的基本单位

​		特点：

​			1、一个仓库中存储一个项目，

​			2、一个用户可以拥有多个仓库，

​			3、一般仓库分为公开的（public），私有的（private）

​		2）Commit：提交

​		特点：

​			1、程序在整个开发周期，有大量的对代码资源进行迭代和修改，都可以通过commit的方式进行记录，便于程序员回溯代码，即使这些代码被删除。

​			2、提交便于使用者观察整个工程的开发流程以设计流程

​		3）Branch：分支

​			特点：

​				1）在仓库中可以包含多个分支，分支才是代码文件的第一存储单位，默认的仓库分支为master / main

​				2）不仅可以管理代码存储，便于多人协作的开发

### 	仓库的内容

​			1）Code：资源存储，代码资源，二进制，项目管理脚本，许可证等等

​			2）issues：使用时遇到的bug或进行提交，等待反馈

​			3）README：使用markdown语言进行编写，工程自述文件，开发进度，版本更新，使用介绍等等

​			4）LISCENSE 许可证：GPL 2.0/3.0，Apache 2.0，Mit，这些许可证，给使用者最大使用权限以及最少的限制

### 	Git软件，分布式版本控制系统

​	概念：仓库管理软件，使用git管理私人代码或企业代码



## Git命令

### 	1、如何让网站的账户与设备绑定，后续完成代码的管理，上传下载

#### 		1）创建空仓库
```bash
	git init	#命令
```

​				结果：会生成.git的隐藏文件夹

#### 		2）查看git仓库配置

​				命令：git config --list

#### 		3）将用户邮箱注册到git仓库中

​				命令：git config --global user.email "注册邮箱"

​				案例：git config --global user.email "2417939337@qq.com"

#### 		4）将用户名注册到git仓库中

​				命令：git config --global user.name "用户名"

​				案例：git config --global user.name "Lanke123"

#### 		5）创建本地密文

​				命令：ssh-keygen -t -rsa -C "注册邮箱"

​				案例：ssh-keygen -t rsa -C "2417939337@qq.com"

#### 		6）去对应的目录查找密文文件

​				步骤：

​					（1）生成密文后，在rsa.pub文件中复制密文，粘贴

​					（2）去用户的settings那里找到SSH key and GPG，点击new ssh key

​					（3）随便起一个密钥姓名，将密文粘贴到下面

​				测试关联是否成功：命令：ssh -T git@github.com

### 	2、为目标仓库起别名，定位目标仓库，后续上传

#### 		添加别名

​			命令：git remote add 仓库别名 ssh地址

​			案例：git remote add origin git@github.com:Lanke123/new_repositor_text.git

#### 		删除别名

​			命令：git remote remove 仓库别名

​			案例：git remote remove origin

### 	3、本地设备和云端仓库交互的逻辑

​			详细逻辑：

​			（1）先将源代码文件压到git缓冲区之中

​				命令：git add 源代码文件名

​				案例：git add code.c

​			（2）需要将源代码文件从git缓冲区发送到git本地仓库中

​				命令：git commit -m "提交说明"

​				案例：git commit -m "first upload"

​			（3）版本更新，push双传到云端仓库，本地上传的分支与云端分支一致，就合并这个分支，如果分支不一致，那么在云端新创建一个分支

​				命令：git push 仓库别名 分支名

​				案例：git push origin master

### 	4、删除本地文件以及git本地仓库中的数据

​			命令：git rm 文件名

​			案例：git rm code.c

​			提示：如果使用git rm会删除本地文件以及git本地仓库中的数据，如果想要找回这个文件是不可能的，但如果仅用rm命令删除了本地文件，那你还可以去本地仓库中恢复这个文件



### 	5、恢复被删除的文件

​			命令：git restore



### 	6、代码的依赖关系被破坏

​		状况：本地内容要比云端的内容新，才能完成更新替换，但是如果直接修改云端内容，会导致版本对不上，本地内容无法再次提交！

​		解决办法：

​		（1）先运用git pull命令拉取云端内容，与本地内容合并或操作，再次git push就可以了

​			命令：git pull --rebase 仓库别名 分支名

​			案例：git pull --rebase origin master

​			操作：

​				（1）保留云端内容，然后再次编译推到云端

​					命令：git rebase --skip

​				（2）保留本地内容，然后再次编译推到云端

​					命令：git rebase --abort

​				（3）合并冲突，结合”git add 文件名“命令一起用于修复冲突，提示开发者，一步一步地有没有解决冲突

​					命令：git rebase --continue


## 标题修饰符

# 一级标题修饰符
## 二级标题修饰符
### 三级标题修饰符
#### 四级标题修饰符
##### 五级标题修饰符

## 正文内容
换行符为 \<br\>

## 修饰符
*斜体*

**粗体**

***粗斜体***

~~删除~~

## 分割线 \-\-\-

---

## 引用符号 \>
> 一码归一码
>> 罗兰
>>> 三级引用
>>>> 四级引用

## 列表
### 无序列表 符号 \*

* 游戏
	* 生化危机
	* 博德之门
	* 女神异闻录
		* 雨宫莲

### 有序列表 符号\ 1.
1. 物理学
	1. 粒子物理学
	2. 原子核物理学
	3. 凝聚态物理学
2. 计算机科学
	1. 分布式结构
	2. 数据结构

### 混合列表 
* 游戏
	1. 生化危机
	2. 博德之门
	3. 废墟图书馆
		* 安吉拉
		
## 表格
名称|技能|排行
--|:--:|--:
罗兰|furioso|1

## 代码块
```c
	#include <stdio.h>
	int main(){
		printf("Hello World!\n");
	}
```

```cpp
	#include <iostream>
	using namespace std;
	int main(){
		cout<<"Hello world"<<endl;
	}
```

```bash
	ls -l
	git push origin master
```
