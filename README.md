# Single-phase-AC-electronic-load
2022年省级全国大学生电子设计竞赛A题，单相交流电子负载，湖北省省特等奖，代码开源

![image](https://github.com/emoestudio/Single-phase-AC-electronic-load/assets/66322166/c7c62e28-496d-4b46-a838-02cd8fbaada6)
![image](https://github.com/emoestudio/Single-phase-AC-electronic-load/assets/66322166/e0ec5e80-1f91-4117-baf2-f5443d20df4c)


![image](https://github.com/emoestudio/Single-phase-AC-electronic-load/assets/66322166/4e4d7b5b-1035-429c-a0b8-cc8a02ee04f0)

![image](https://github.com/emoestudio/Single-phase-AC-electronic-load/assets/66322166/974f99e3-68be-4107-95ba-e17de840f3a2)


# 功能汇总

1. 板子设计紧凑美观噪音小，高功率密度

2. 全隔离

3. 功率因数0.1~1 容感性可调 注意功率因数最低能到0.1，报告写的0.5不够极限

4. 输出电压与输入电压相位跟随

5. 输入电流THD低，2%以下

6. **屏幕显示（界面好看）**

   1. 有功无功功率显示
   2. 电压电流电阻检测显示

7. 模式

   1. CC 0.2A~2.5A可调，分辨率0.1A
   2. CR 12欧~150欧可调，分辨率0.5欧
   3. **CP 10~70W可调，分辨率0.5W**
   4. **CS 10~70VA可调，分辨率0.5VA**
   5. 不控整流负载模拟（输出大概给个调制比）

8. 保护

   1. 输入过压
   2. 负载丢失
   3. **输入过流**
   4. 自恢复
## 一些方法

1. 降低功耗到3W内
   1. 换开关频率 区别不大，在波动范围内
   2. 改PI参数 极限了（实际上确实改这个用处不大）
   3. 屏幕亮度
   4. 换MOS
   5. 辅电 想隔离，还是算了
   6. 电感 已经改了
   7. 降低CPU主频 降了一点点，发现增大THD，还是算了
2. 输入电流THD恒小于3%
   1. 改PI参数
3. PF 0.999
4. PF可调并且较为准确 用数组拟合
5. PF范围宽 数组拟合
6. CC、CR、CP、
   
