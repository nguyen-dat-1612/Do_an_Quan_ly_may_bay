# Do_an_Quan_ly_may_bay
Đồ án quản lý máy bay PTIT khóa 2021.
ĐỀ BÀI:
Quản lý các chuyến bay nội địa thuộc 1 hãng hàng không:
Ta có các danh sách sau:
- Máy bay: mảng con trỏ có tối đa 300 máy bay. 
•	Mỗi máy bay có các thông tin (Số hiệu MB (C15), loại máy bay (C40), số dãy, số dòng); 
•	Mỗi máy bay có 1 số hiệu duy nhất; (số chỗ = số dãy * số dòng ), số chỗ >=20
•	Nếu số dãy = 5 nghĩa là máy bay có các dãy A, B, C, D, E; Nếu số dòng = 20 nghĩa là máy bay có các hàng ghế được đánh số từ 1 đến 20. Kết hợp dãy và hàng ghế ta sẽ có số vé.
•	Theo ví dụ trên, ta có 100 vé với các số vé A01, A02, ...., A19, A20, …, E19, E20
- Chuyến bay: 
•	danh sách liên kết đơn ( Mã CB (C15),  
•	Ngày giờ khởi hành, sân bay đến , trạng thái, Số hiệu MB, danh sách vé). 
•	Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ; 
•	danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó.  
•	Danh sách chuyến bay luôn có sẵn thứ tự theo mã chuyến bay.
- Hành khách: cây nhị phân tìm kiếm (Số CMND , Ho, Ten,  Phai)
Chương trình có các chức năng sau: 
a/ Cập nhập danh sách các máy bay (thêm / xóa / hiệu chỉnh)
b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay , hủy chuyến.
c/Đặt vé: cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra. Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.
d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.
e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:
DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######
Ngày giờ khởi hành: dd/mm/yyyy hh:mm.  Nơi đến : xxxxxxxxxxx

	STT	SỐ VÉ		SỐ CMND	HỌ TÊN	PHÁI
f/ In danh sách các chuyến bay khởi hành trong  ngày dd/mm/yyyy đến nơi XXXX mà còn vé (cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)
g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần. Kết xuất:
	Số hiệu máy bay		Số lượt thực hiện chuyến bay

Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập liệu làm dữ liệu bị sai. 

CHỨC NĂNG:
1. MÁY BAY (thêm, xóa, hiệu chỉnh)
2. CHUYẾN BAY (thêm,cancle,hiệu chỉnh ngày giờ)
3. ĐẶT VÉ(thêm hành khách)
4. HỦY VÉ
5. In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay
6. Thống kê số lượt thực hiện chuyến bay của từng máy bay

LƯU Ý
-	Đối với con trỏ sử dụng toán tử new phải giải phóng vùng nhớ, cần giải phóng bộ nhớ trong xóa máy bay
-	Chú ý làm kĩ các file
-	Chú ý bắt lỗi thời gian
-	Chú ý phần nhập chuỗi kí tự trên màn hình ( Nhập thừa khoảng trắng ở cuối, ở giữa và ở đầu; về kí tự thường và hoa)
-	Lưu ý cực kì quan trọng: Nếu có gì thắc mắc về logic của chương trình thì chủ động hỏi thầy để biết chi tiết
  
NHẬN XÉT CỦA THẦY: 
Sai đề ở phần giới hạn số dãy số chỗ ngồi của máy bay:
Cụ thể: Mình làm giới hạn số dãy tối đa là 5 và số dòng tối đa là 20. Theo đề phải là số dãy lớn hơn 5 và số dòng lớn hơn 20. Ảnh hưởng đến số vé của chuyến bay.
Sai đề ở phần xóa một máy bay:
Cụ thể: Xóa máy bay -> những chuyến bay tương lai bị hủy chuyến. Theo thầy chỉ xóa máy bay khi không có chuyến bay trong tương lai.

CÀI THƯ VIỆN:
Tham khảo: https://www.youtube.com/watch?v=mQfiVtDBSfw

NHỮNG LƯU Ý VỀ LÀM VIỆC ĐỒ ÁN VÀ THI:
Về đồ án:
Ở phần khai báo các bạn nên chia mỗi người làm một danh sách.
Khi chia câu cho mỗi người làm thì nên chia sao cho đều. Đều ở đây là mỗi người đều được tiếp cận với mỗi phần ở trong chương trình để hiểu rõ chương trình, không phải là tôi làm hết những câu trên phần máy bay, bạn làm hết các câu trên phần chuyến bay …
Có thời gian thì nên tối ưu thuật toán. Đặc biệt với thuật toán tìm kiếm và sắp xếp.
Về thi: (khoảng dưới 30p)
Thầy sẽ hỏi về thuật toán chứ không quan tâm về đồ họa nhưng thầy sẽ có thể hỏi thuật toán chạy thế nào mà em in ra 9 máy bay này trên 1 trang rồi sang trang em in ra được mấy cái phía sau.
Thầy sẽ bảo giải thích thuật toán chạy như thế nào? Nếu sai hỏi biết sai chỗ nào không và hỏi biết sửa không? Nếu thuật toán chưa tối ưu thì thầy sẽ hỏi làm thế nào để tối ưu, dùng thuật toán nào để tối ưu?
Nếu một bạn trả lời không được thì thầy sẽ hỏi bạn còn lại có hiểu phần bạn đó làm không và giải thích nên tốt nhất bạn nào cũng phải hiểu hết toàn bộ chương trình.
Cuối cùng thầy sẽ có một câu hỏi phụ hoặc cho làm bài tập, câu hỏi phụ thường là một file có số phần tử, mảng có bao nhiêu phần tử thì làm cách nào load file và sắp xếp phần tử:  nhanh nhất, tối ưu nhất và tiết kiệm bộ nhớ nhất
Về điểm thi:
Mỗi người sẽ có điểm riêng tùy thuộc vào mức độ hiểu biết của bản thân trong quá trình vấn đáp với Thầy.
