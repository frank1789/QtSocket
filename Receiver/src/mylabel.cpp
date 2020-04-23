#include "mylabel.hpp"

#include "instrumentor.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {}

void MyLabel::setImage(QImage image) {
  PROFILE_FUNCTION();
  QPixmap pixmap = QPixmap::fromImage(image);
  setPixmap(
      pixmap.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}

void MyLabel::updatePixmap(QPixmap image) {
  PROFILE_FUNCTION();
  setPixmap(
      image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}

// #include <QPainter>
// #include <QBrush>
// #include <QPen>
// #include <QFont>
// #include <QPen>
// #include <QBrush>
// #include <QPen>

// QImage MyLabel::drawBoxes(QImage &image, QRect &rect, QString captions)
// {

//     // ColorManager cm;
//     QPainter p;
//     QBrush   brush;
//     QPen     pen;
//     QFont    font;
//     QPen     fPen;
//     QBrush   bBrush;
//     QPen     bPen;

//     // Configure pen
//     pen.setStyle(Qt::SolidLine);
//     pen.setWidthF(2);

//     // Configure font pen
//     fPen.setStyle(Qt::SolidLine);
//     fPen.setColor(Qt::black);

//     // Configure back pen
//     bPen.setStyle(Qt::SolidLine);

//     // Configure brush
//         brush.setStyle(Qt::NoBrush);

//     // Configure back brush
//     bBrush.setStyle(Qt::SolidPattern);

//         // Configure font
//         font.setCapitalization(QFont::Capitalize);
//         font.setPixelSize(12);

//         // Configure painter
//         p.setRenderHint(QPainter::Antialiasing);
//         p.setFont(font);

//         QFontMetrics fm(font);

//         // Draw each box
//     //     for(int i=0;i<boxes.count();i++)
//     //     {
//     //         // Check min confidence value and active label
//     //         if (confidences[i] >= minConfidence &&
//     activeLabels[captions[i]])
//     //         {
//     //             // Draw box
//     //             cm.setRgb(rgb);
//                 // pen.setColor(cm.getColor(captions[i]));
//     //             p.setPen(pen);
//     //             p.setBrush(brush);
//     //             p.drawRect(boxes[i]);

//     //             // Format text
//     //             QString confVal = QString::number(qRound(confidences[i] *
//     100)) + " %";
//     //             QString text    = captions[i] + " - " + confVal;

//     //             // Text rect
//     //             int width  = fm.width(text)+FONT_WIDTH_MARGIN;
//     //             int height = fm.height();
//     //             int left   = boxes[i].left()>=0 ? int(boxes[i].left()) :
//     int(boxes[i].right()-width);
//     //             int top    = boxes[i].top()-fm.height()>=0 ?
//     int(boxes[i].top()-fm.height()) : int(boxes[i].bottom());

//     //             // Text position
//     //             int tLeft = left+FONT_WIDTH_MARGIN/2;
//     //             int tTop  = boxes[i].top()-fm.height()>=0 ?
//     int(boxes[i].top() - FONT_HEIGHT_MARGIN) : int(boxes[i].bottom() + height
//     - FONT_HEIGHT_MARGIN);

//     //             // Draw text background
//     //             bPen.setColor(pen.color());
//     //             bBrush.setColor(pen.color());
//     //             p.setPen(bPen);
//     //             p.setBrush(bBrush);
//     //             p.drawRect(left,top,width,height);

//     //             // Draw tex
//     //             p.setPen(fPen);
//     //             p.drawText(tLeft,tTop,text);
//     //         }
//     //     }
//     // }

//     return image;
// }

// void LeptonThread::recalculateResult(const QImage &thermal, const QImage
// &rgb) {
//   PROFILE_FUNCTION();
//   QPainter painter(&m_result);
//   painter.setCompositionMode(QPainter::CompositionMode_Source);
//   painter.fillRect(m_result.rect(), Qt::transparent);
//   painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
//   painter.drawImage(0, 0, thermal);
//   painter.setCompositionMode(m_mode);
//   painter.drawImage(0, 0, rgb);
//   painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
//   painter.fillRect(m_result.rect(), Qt::white);
//   painter.end();
//   emit updateOverlay(m_result);
// }

// QImage AuxUtils::drawText(const QImage &image, const QRectF &rect, const
// QString &text)
//     QPainter     p;
//     QPainterPath path;
//     QPen         pen;
//     QBrush       brush;
//     QStringList  lines;
//     QFont font;
//   // Configure font
//   font.setPixelSize(AuxUtils::sp(FONT_PIXEL_SIZE_TEXT,rect.size()));
//   font.setStyleHint(QFont::Times, QFont::PreferAntialias);

//         // Configure pen
//         pen.setWidthF(borderSize);
//         pen.setStyle(Qt::SolidLine);
//         pen.setColor(borderColor);
//         pen.setCapStyle(Qt::RoundCap);
//         pen.setJoinStyle(Qt::RoundJoin);

//         // Configure brush
//         brush.setStyle(Qt::SolidPattern);
//         brush.setColor(fontColor);

//         // Calculate text position
//         QFontMetrics fm(font);
//         for(int i=0;i<lines.count();i++)
//         {
//             // Calculate x0 and y0 positions
//             int x = ((r.width()) - fm.width(lines.at(i)))/2;
//             int y = pos == Qt::AlignBottom ? (r.height()) -
//             fm.height()*(lines.count()-i) : (fm.height()*(i+1));

//             // Add text to path
//             path.addText(r.left()+x,r.top()+y,font,lines.at(i));
//         }

//         // Set pen, brush, font and draw path
//         p.setRenderHints(QPainter::TextAntialiasing |
//         QPainter::Antialiasing); p.setPen(pen); p.setBrush(brush);
//         p.setFont(font);
//         p.drawPath(path);
//     }

//     return image;
// }
