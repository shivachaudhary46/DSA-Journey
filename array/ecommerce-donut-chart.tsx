import React, { useState } from 'react';

const EcommerceChart = () => {
  const [hoveredSegment, setHoveredSegment] = useState(null);

  const data = [
    { 
      label: 'Consumer Electronics & Smartphones', 
      value: 28, 
      color: '#0B389D' 
    },
    { 
      label: 'Fashion & Apparel', 
      value: 22, 
      color: '#2F57AB' 
    },
    { 
      label: 'Computing & Laptops', 
      value: 18, 
      color: '#6581BF' 
    },
    { 
      label: 'Home Appliances & Smart Living', 
      value: 12, 
      color: '#A1B3D7' 
    },
    { 
      label: 'Personal Care, Beauty & Baby Essentials', 
      value: 10, 
      color: '#8FA3CC' 
    },
    { 
      label: 'Health & Wellness', 
      value: 8, 
      color: '#B5C4E0' 
    },
    { 
      label: 'Audio & Wearables', 
      value: 2, 
      color: '#D7DCEA' 
    }
  ];

  const total = data.reduce((sum, item) => sum + item.value, 0);
  
  const createSegments = () => {
    let currentAngle = -90;
    
    return data.map((item, index) => {
      const percentage = (item.value / total) * 100;
      const angle = (percentage / 100) * 360;
      const startAngle = currentAngle;
      const endAngle = currentAngle + angle;
      
      const largeArcFlag = angle > 180 ? 1 : 0;
      
      const outerRadius = hoveredSegment === index ? 210 : 195;
      const innerRadius = 120;
      
      const startX = 300 + outerRadius * Math.cos((startAngle * Math.PI) / 180);
      const startY = 300 + outerRadius * Math.sin((startAngle * Math.PI) / 180);
      const endX = 300 + outerRadius * Math.cos((endAngle * Math.PI) / 180);
      const endY = 300 + outerRadius * Math.sin((endAngle * Math.PI) / 180);
      
      const innerStartX = 300 + innerRadius * Math.cos((endAngle * Math.PI) / 180);
      const innerStartY = 300 + innerRadius * Math.sin((endAngle * Math.PI) / 180);
      const innerEndX = 300 + innerRadius * Math.cos((startAngle * Math.PI) / 180);
      const innerEndY = 300 + innerRadius * Math.sin((startAngle * Math.PI) / 180);
      
      const path = `
        M ${startX} ${startY}
        A ${outerRadius} ${outerRadius} 0 ${largeArcFlag} 1 ${endX} ${endY}
        L ${innerStartX} ${innerStartY}
        A ${innerRadius} ${innerRadius} 0 ${largeArcFlag} 0 ${innerEndX} ${innerEndY}
        Z
      `;
      
      const midAngle = (startAngle + endAngle) / 2;
      const labelRadius = 240;
      const labelX = 300 + labelRadius * Math.cos((midAngle * Math.PI) / 180);
      const labelY = 300 + labelRadius * Math.sin((midAngle * Math.PI) / 180);
      
      const connectorRadius = 200;
      const connectorX = 300 + connectorRadius * Math.cos((midAngle * Math.PI) / 180);
      const connectorY = 300 + connectorRadius * Math.sin((midAngle * Math.PI) / 180);
      
      currentAngle = endAngle;
      
      return {
        path,
        percentage,
        labelX,
        labelY,
        connectorX,
        connectorY,
        midAngle,
        ...item,
        index
      };
    });
  };

  const segments = createSegments();

  return (
    <div className="min-h-screen flex items-center justify-center p-8 relative overflow-hidden bg-white">

      {/* Main container */}
      <div className="relative w-full max-w-7xl">
        <h1 className="text-6xl font-light mb-16 ml-8" style={{ color: '#0B389D' }}>E-commerce Categories</h1>
        
        <div className="relative">
          <svg width="600" height="600" className="mx-auto">
            {/* Chart segments */}
            {segments.map((segment) => (
              <g key={segment.index}>
                <path
                  d={segment.path}
                  fill={segment.color}
                  className="cursor-pointer transition-all duration-300"
                  style={{
                    filter: hoveredSegment === segment.index 
                      ? 'drop-shadow(0 0 15px rgba(11, 56, 157, 0.4)) brightness(1.1)' 
                      : 'drop-shadow(0 4px 10px rgba(0, 0, 0, 0.15))',
                    opacity: hoveredSegment === segment.index ? 1 : 0.95
                  }}
                  onMouseEnter={() => setHoveredSegment(segment.index)}
                  onMouseLeave={() => setHoveredSegment(null)}
                />
                
                {/* Connector line */}
                <line
                  x1={segment.connectorX}
                  y1={segment.connectorY}
                  x2={segment.labelX}
                  y2={segment.labelY}
                  stroke="rgba(156, 163, 175, 0.4)"
                  strokeWidth="1.5"
                />
                
                {/* Connector dot */}
                <circle
                  cx={segment.connectorX}
                  cy={segment.connectorY}
                  r="3"
                  fill="rgba(156, 163, 175, 0.6)"
                />
              </g>
            ))}
            
            {/* Center circle */}
            <circle
              cx="300"
              cy="300"
              r="115"
              fill="white"
              style={{
                filter: 'drop-shadow(0 2px 8px rgba(0, 0, 0, 0.1))'
              }}
            />
            
            {/* Center text */}
            <text
              x="300"
              y="285"
              textAnchor="middle"
              className="text-base font-light tracking-wider"
              fill="#6581BF"
            >
              MARKET SHARE
            </text>
            <text
              x="300"
              y="315"
              textAnchor="middle"
              className="text-4xl font-light tracking-wide"
              fill="#0B389D"
            >
              100%
            </text>
            <text
              x="300"
              y="335"
              textAnchor="middle"
              className="text-sm font-light"
              fill="#6581BF"
            >
              Nepal Market
            </text>
          </svg>
          
          {/* Labels positioned around the chart */}
          {segments.map((segment) => (
            <div
              key={segment.index}
              className="absolute cursor-pointer transition-all duration-200"
              style={{
                left: `${segment.labelX}px`,
                top: `${segment.labelY}px`,
                transform: 'translate(-50%, -50%)',
                textAlign: segment.midAngle > -90 && segment.midAngle < 90 ? 'left' : 'right'
              }}
              onMouseEnter={() => setHoveredSegment(segment.index)}
              onMouseLeave={() => setHoveredSegment(null)}
            >
              <div className={`${segment.midAngle > -90 && segment.midAngle < 90 ? 'pl-8' : 'pr-8'}`}>
                <div className="text-lg font-light" style={{ color: '#0B389D' }}>
                  {segment.label} <span className="font-semibold">{segment.value}%</span>
                </div>
              </div>
            </div>
          ))}
        </div>
      </div>

      <style>{`
        @keyframes float {
          0%, 100% { transform: translate(0, 0) scale(1); }
          33% { transform: translate(40px, -60px) scale(1.15); }
          66% { transform: translate(-30px, 30px) scale(0.95); }
        }
      `}</style>
    </div>
  );
};

export default EcommerceChart;