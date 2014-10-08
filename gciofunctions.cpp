#include "gciofunctions.h"


Chromatogramm ReadChroFile(QFile *file)
{
    QTextStream in(file);

    double rtime, intens;
    bool rt_ok, int_ok;

    Chromatogramm out;

    QString line = in.readLine();
    while (!line.isNull()) {

        //QTextStream (&line) >> rtime >> intens;
        QStringList sl = line.split("\t");

        if(sl.count() == 2)
        {
            rtime = sl.at(0).toDouble(&rt_ok);
            intens = sl.at(1).toDouble(&int_ok);

            if(rt_ok && int_ok && rtime>=0.0 /*&& intens>=0.0*/)
            {
                out.retentiontime << rtime;
                out.intensity << intens;
                //qDebug() << "Read" << rtime << ":" << intens;
            }
        }
        line = in.readLine();
    }
    return out;
}

double ASYM2SIG(double x, double y0, double xc, double height, double hwhm, double w2, double w3)
  {return y0 + height * ((1 /(1+exp(-(x-xc+hwhm/2)/w2))) * (1-1 /(1+exp(-(x-xc-hwhm/2)/w3)))); }

double ECS(double x, double y0, double center, double area, double width, double a3, double a4)
{
    return y0+area/(width*2*3.1415926)*(exp(-0.5*pow((x-center)/width, 2))*(1+(a3/(3*2*1))*((x-center)/width)*(pow((x-center)/width, 2)-3)
             +(a4/(4*3*2*1))*(pow((x-center)/width,4)-6*pow((x-center)/width, 3)+3)
             +((10*pow(a3,2))/(6*5*4*3*2*1))*(pow((x-center)/width, 6)-15*pow((x-center)/width,4)+45*pow((x-center)/width,2)-15)));
}

