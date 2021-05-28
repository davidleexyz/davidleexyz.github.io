### Smooth Streaming
manifest
duration, chunks, video, audio


MP4(由box组成)
ftyp => 第一个box
moov => metadata => 初始化 视频时长大小 宽高 音量大小 帧信息
mdat => 包含音视频信息 帧数据按顺序存放

FMP4
moov => 包含track 信息
moof => meta data
mdat => 音视频数据帧

### MediaPlayer框架

Nuplayer => setDataSource => MediaSource => MediaExtract sniffer 判断媒体类型 => mVideoTrack / mAudioTrack
		 => NuPlayerRender => postScanSource => init Decoder => NuPlayerDecoder => ACodec => omx => Render => audoTrack / videoSurface


### Redis集群

Node1 (master + slave) <-> Node2 (master + slave) ...
集群模式不支持读写分离, 读写都在master节点, slave节点作为热备
Node节点之间通过gossip协议通信

哈希槽分区算法 (16384个hash slots)
slotnum = CRC(key) / 16384 
保证了slots与节点的对应关系, 哪些slot有当前的节点管理

重定向机制 (moved, ask)
MOVED表示访问的slot已经失效在其它节点上, 返回moved的消息给客户端, 客户端再去其它节点做读写请求
ASK表示正在做数据迁移, 返回ask消息到客户端, 客户端发送ASKING请求

GOSSIP协议 (meet, ping, pong, fail)

扩容和缩容


### 量化算法
对称和非对称/饱和和不饱和

KL divergency

P, Q 两个集合的相对熵越小 两个集合的近似度越高

KLD = Sum[P(i) * log(P(i)) - P(i) * log(Q(i))]
衡量两个概率分布的距离

(min, max) => (-127, 127) 将分布的数据做截断=> 截断的依据是什么? (threshold) <= 算KLD
对称
s = rmax / qmax

非对称
s = (rmax - rmin) / (qmax - qmin)
r = (q - zp) * s => zp = qmax - rmax / s


### 模型压缩
稀疏化 / filter pruning

- mangnitude ->  threshold (search) -> set to zero -> fine tuning
- l0 -> traing的时候 加上l0 惩罚项 -> weight 会更稀疏

- l1 / l2 算每个filter channel 与其它 filter channel 的 l1 和 l2 距离


### EasyQuant
1. 初始化 activation 与 weight 的 scale, Sa 和 Sw
2. 固定Sa, 搜索Sw  [alpha* Sw, beta * Sw] alpha = 0.2, beta = 3
 => 计算每一层 int8 activation dequant后的值与原始fp32的cosin相似度
3. 固定Sw, 搜索Sa  [alpha* Sa, beta * Sa] alpha = 0.2, beta = 3
 => 计算每一层 int8 activation dequant后与原始fp32的cosin相似度


### QAT
1. create training graph
2. training with sub dataset and don't enable quant
3. collect range of activation
4. init quantizer op with scale, zero point, min, max
5. do forward with quantization and dequantization for output
6. update activation range using exponetial moving average (Vt = beta * Vt-1 + (1-beta) * θt)
7. do backward and update weight
8. repeat 4 to 7
