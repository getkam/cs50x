from fpdf import FPDF
from PIL import Image

def main():
    pdf = FPDF(orientation='portrait', unit='mm', format='A4')
    pdf.add_page()

    pdf.set_font('helvetica', size = 26)
    header = "CS50 Shirtificate"
    header_width = pdf.get_string_width(header)
    page_width = pdf.w
    x_position = (page_width - header_width) / 2
    pdf.text(x_position, 20, header)

    img = Image.open('shirtificate.png')
    max_width_mm = pdf.w - 20
    max_hight_mm = pdf.h - 20

    img_width_px, img_hight_px = img.size
    dpi = 72
    img_width_mm = img_width_px / dpi * 25.4
    img_hight_mm = img_hight_px / dpi * 25.4

    scale = min(max_width_mm / img_width_mm, max_hight_mm/img_hight_mm)
    img_width_mm *= scale
    img_hight_mm *= scale

    x_img = (pdf.w - img_width_mm) / 2
    y_img = (pdf.h - img_hight_mm) / 2
    pdf.image(img, x_img, y_img, img_width_mm, img_hight_mm )


    name = input("Name: ")
    text = name + " took CS50"

    txt_width = pdf.get_string_width(text)
    text_x_position = (pdf.w - txt_width) / 2
    text_y_position = y_img + img_hight_mm / 3
    pdf.set_text_color(255,255,255)
    pdf.text(text_x_position, text_y_position, text)

    pdf.output("shirtificate.pdf")

if __name__ == "__main__":
    main()
