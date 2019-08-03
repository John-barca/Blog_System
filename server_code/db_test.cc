#include "db.hpp"

//使用测试程序，检测刚才写的MySQL程序是否正确
//单元测试
#if 0
void TestBlogSystem(){
    Json::StyledWriter writer;
    MYSQL* mysql = blog_system::MySQLInit();
    blog_system::BlogTable blog_table(mysql);
    Json::Value blog;
    
    //测试插入
    //blog["title"] = "我的第一篇博客";
    //blog["content"] = "我要拿三十";
    //blog["tag_id"] = 1;
    //blog["create_time"] = "2019/07/28";
    //bool ret = blog_table.Insert(blog);
    //printf("insert: %d\n", ret);

    //测试查找多条
    //Json::Value blogs;
    //bool r = blog_table.SelectAll(&blogs);
    //printf("select all %d\n", r);
    //printf("blogs: %s\n", writer.write(blogs).c_str());

    //测试查找单个博客
    //bool ret = blog_table.SelectOne(2, &blogs);
    //printf("select one %d!\n", ret);
    //printf("blogs: %s\n", writer.write(blogs).c_str());
    
    //测试修改博客
   
    //blog["blog_id"] = 2;
    //blog["title"] = "这是个修改后的博客";
    //blog["content"] = "已修改";
    //blog["tag_id"] = 2;
    //blog["create_time"] = "2019/07/29";
    //bool ret = blog_table.Update(blog);
    //printf("Update : %d\n", ret);
    //测试删除
    bool ret = blog_table.Delete(1);
    printf("Delete: %d", ret);

    blog_system::MySQLRelease(mysql);
}
#endif

//测试标签操作
void TestTagTable(){
    MYSQL* mysql = blog_system::MySQLInit();
    blog_system::TagTable tagtable(mysql);
    Json::Value tag;
    //测试插入标签
    //tag["tag_name"] = "C语言";
    //bool ret = tagtable.Insert(tag);
    //printf("insert: %d\n", ret);
    Json::StyledWriter Writer;

    //测试查找标签
    //bool ret = tagtable.SelectAll(&tag);
    //printf("Select All %d\n", ret);
    //printf("tag : %s\n", Writer.write(tag).c_str());

    //测试删除标签
    bool ret = tagtable.Delete(1);
    printf("Delete tag %d!\n", ret);


    blog_system::MySQLRelease(mysql);
}

int main(){
    TestTagTable();
    return 0;
}