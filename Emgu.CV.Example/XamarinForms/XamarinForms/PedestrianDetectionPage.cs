﻿//----------------------------------------------------------------------------
//  Copyright (C) 2004-2015 by EMGU Corporation. All rights reserved.       
//----------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Drawing;
using System.Threading.Tasks;

using Emgu.CV;
using Emgu.CV.CvEnum;
using Emgu.CV.Structure;
using Emgu.Util;

using PedestrianDetection;

namespace Emgu.CV.XamarinForms
{
   public class PedestrianDetectionPage : ButtonTextImagePage
   {
      public PedestrianDetectionPage()
         : base()
      {
         var button = this.GetButton();
         button.Text = "Perform Pedestrian Detection";
         button.Clicked += OnButtonClicked;
      }

      private async void OnButtonClicked(object sender, EventArgs e)
      {
         GetLabel().Text = "please wait...";
         SetImage(null);

         Task<Tuple<Mat, long>> t = new Task<Tuple<Mat, long>>(
            () =>
            {
               long time;
               Mat image = LoadImage("pedestrian.png");

               if (image == null)
                  return new Tuple<Mat, long>(null, 0);
               Rectangle[] pedestrians = FindPedestrian.Find(image, false, out time);

               foreach (Rectangle rect in pedestrians)
               {
                  CvInvoke.Rectangle(image, rect, new MCvScalar(0, 0, 255), 2);
               }

               return new Tuple<Mat, long>(image, time);
            });

         t.Start();
         var result = await t;
         String computeDevice = CvInvoke.UseOpenCL ? "OpenCL: " + OclDevice.Default.Name : "CPU";
         GetLabel().Text = String.Format("Detection completed with {1} in {0} milliseconds.", t.Result.Item2, computeDevice);
         SetImage(t.Result.Item1);
      }
   }
}
