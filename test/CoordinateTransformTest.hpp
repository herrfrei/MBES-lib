/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/*
 * File:   CoordinateTransformTest.cpp
 * Author: glm,jordan
 *
 */

#include "catch.hpp"
#include "../src/math/CoordinateTransform.hpp"
#include <Eigen/Dense>
#include "../src/Position.hpp"
#include <math.h>

#define POSITION_PRECISION 0.00000001

/**Test if the coordinate transform works*/
TEST_CASE("Coordinate Transform Test") {

    // prime meridian, equator, on ellipsoid
    Position primeMeridianEquator(0, 0, 0, 0);

    Eigen::Vector3d testPositionECEF;
    CoordinateTransform::getPositionECEF(testPositionECEF,primeMeridianEquator);

    Eigen::Vector3d expectedPositionECEF;
    expectedPositionECEF << 6378137.0 , 0, 0;

    REQUIRE( testPositionECEF.isApprox(expectedPositionECEF, POSITION_PRECISION) );

    // North Pole on ellipsoid
    Position northPole(0, 90, 0, 0);
    Eigen::Vector3d northPoleECEF;
    CoordinateTransform::getPositionECEF(northPoleECEF,northPole);

    Eigen::Vector3d expectedNorthPoleECEF;
    expectedNorthPoleECEF << 0, 0, 6356752.3142; // WGS 84 polar semi-minor axis

    double northPolePrecision = 0.00000001;
    REQUIRE( northPoleECEF.isApprox(expectedNorthPoleECEF, northPolePrecision) );

    

}

/**test if the conversion between ECEF and longitude latitude height works*/
TEST_CASE("Conversions between ECEF and Longitude Latitude Height") {
    Position testPosition(0, 48, -68, 10);

    Eigen::Vector3d testPositionECEF;
    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    Position expectedPosition(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, 60, 79, -100);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, -60, -79, 100);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, -70, 48, 90);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, 70, 60, 80);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, 0, 0, 0);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, -80, -40, -50);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
    
    testPosition = Position(0, 87, -43, -59);

    CoordinateTransform::getPositionECEF(testPositionECEF,testPosition);

    expectedPosition = Position(0,0,0,0);
    CoordinateTransform::convertECEFToLongitudeLatitudeElevation(testPositionECEF, expectedPosition);

    //std::cout << "expectedPosition:" << std::endl;
    //std::cout << expectedPosition << std::endl;

    REQUIRE(abs((roundf(expectedPosition.getLatitude()*100)/100)-testPosition.getLatitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getLongitude()*100)/100)-testPosition.getLongitude())<1e-10);
    REQUIRE(abs((roundf(expectedPosition.getEllipsoidalHeight()*100)/100)-testPosition.getEllipsoidalHeight())<1e-10);
}

/**Test if the conversion between spherical to cartesian works*/
TEST_CASE("Conversion between spherical to cartesian"){
    Eigen::Vector3d v;

    CoordinateTransform::spherical2cartesian(v,45,45,1);

    REQUIRE(abs(v(0) - 0.5) < 0.000000001);
    REQUIRE(abs(v(1) - 0.5) < 0.000000001);
    REQUIRE(abs(v(2) - 0.707107) < 0.000001);
}

/**Test if the conversion between sonar to cartesian works*/
TEST_CASE("Conversion between sonar to cartesian"){
    Eigen::Vector3d v;
    CoordinateTransform::sonar2cartesian(v,90,0,1);
    REQUIRE(std::abs(v(0)-1)<1e-10);
    REQUIRE(std::abs(v(1)-0)<1e-10);
    REQUIRE(std::abs(v(2)-0)<1e-10);
    CoordinateTransform::sonar2cartesian(v,0,90,1);
    REQUIRE(std::abs(v(0)-0)<1e-10);
    REQUIRE(std::abs(v(1)-1)<1e-10);
    REQUIRE(std::abs(v(2)-0)<1e-10);
    CoordinateTransform::sonar2cartesian(v,0,0,1);
    REQUIRE(std::abs(v(0)-0)<1e-10);
    REQUIRE(std::abs(v(1)-0)<1e-10);
    REQUIRE(std::abs(v(2)-1)<1e-10);
}

/**Test if the conversion between NED to ECEF position works*/
TEST_CASE("Conversion between NED to ECEF position")
{
    Position nedPos(0,0,0,0);
    Eigen::Matrix3d mECEF;
    CoordinateTransform::ned2ecef(mECEF,nedPos);
    Eigen::Matrix3d matrixSearch;
    matrixSearch << 0,0,-1,
                    0,1,0,
                    1,0,0;
    REQUIRE(mECEF == matrixSearch);
    
    nedPos = Position(0,16,19,0);
    CoordinateTransform::ned2ecef(mECEF,nedPos);
    matrixSearch << -0.260620240054051,-0.325568154457157,-0.908890789521783,
                    -0.0897387452327910,0.945518575599317,-0.312956196296995,
                    0.961261695938319,0,-0.275637355816999;
    REQUIRE(abs(mECEF(0,0)-matrixSearch(0,0))< 1e-10);
    REQUIRE(abs(mECEF(0,1)-matrixSearch(0,1))< 1e-10);
    REQUIRE(abs(mECEF(0,2)-matrixSearch(0,2))< 1e-10);
    REQUIRE(abs(mECEF(1,0)-matrixSearch(1,0))< 1e-10);
    REQUIRE(abs(mECEF(1,1)-matrixSearch(1,1))< 1e-10);
    REQUIRE(abs(mECEF(1,2)-matrixSearch(1,2))< 1e-10);
    REQUIRE(abs(mECEF(2,0)-matrixSearch(2,0))< 1e-10);
    REQUIRE(abs(mECEF(2,1)-matrixSearch(2,1))< 1e-10);
    REQUIRE(abs(mECEF(2,2)-matrixSearch(2,2))< 1e-10);
}

/**Test if the conversion between Terrestial to Geodetic works*/
TEST_CASE("Conversion between Terrestial to Geodetic")
{
    Position pos(0,0,0,0);
    Eigen::Matrix3d mGeo;
    CoordinateTransform::getTerrestialToLocalGeodeticReferenceFrameMatrix(mGeo,pos);
    Eigen::Matrix3d matrixSearch;
    matrixSearch << 0,0,1,
                    0,1,0,
                    -1,0,0;
    REQUIRE(mGeo == matrixSearch);
    
    pos = Position(0,45,56,0);
    CoordinateTransform::getTerrestialToLocalGeodeticReferenceFrameMatrix(mGeo,pos);
    matrixSearch << -0.395409094035560,-0.586218089412104,0.707106781186548,
                    -0.829037572555042,0.559192903470747,0,
                    -0.395409094035560,-0.586218089412104,-0.707106781186548;
    REQUIRE(abs(mGeo(0,0)-matrixSearch(0,0))< 1e-10);
    REQUIRE(abs(mGeo(0,1)-matrixSearch(0,1))< 1e-10);
    REQUIRE(abs(mGeo(0,2)-matrixSearch(0,2))< 1e-10);
    REQUIRE(abs(mGeo(1,0)-matrixSearch(1,0))< 1e-10);
    REQUIRE(abs(mGeo(1,1)-matrixSearch(1,1))< 1e-10);
    REQUIRE(abs(mGeo(1,2)-matrixSearch(1,2))< 1e-10);
    REQUIRE(abs(mGeo(2,0)-matrixSearch(2,0))< 1e-10);
    REQUIRE(abs(mGeo(2,1)-matrixSearch(2,1))< 1e-10);
    REQUIRE(abs(mGeo(2,2)-matrixSearch(2,2))< 1e-10);
}

/**Test if CoordinateTransform get a valid DCM*/
TEST_CASE("getDCM Test") {

    Eigen::Vector3d testVector = Eigen::Vector3d::Ones();

    Attitude attitudeZero(0, 0, 0, 0);
    Eigen::Matrix3d dcmAttitudeZero;
    CoordinateTransform::getDCM(dcmAttitudeZero,attitudeZero);
    REQUIRE(dcmAttitudeZero.isIdentity());

    // roll 180 degrees
    Attitude attitudeRoll(0, 180, 0, 0);
    Eigen::Matrix3d dcmFromAttitudeRollTest;
    CoordinateTransform::getDCM(dcmFromAttitudeRollTest,attitudeRoll);
    Eigen::Vector3d testRollVector = dcmFromAttitudeRollTest * testVector;

    double testRollPrecision = 0.000000001;
    REQUIRE(abs(testRollVector(0) - 1.0) < testRollPrecision);
    REQUIRE(abs(testRollVector(1) - -1.0) < testRollPrecision);
    REQUIRE(abs(testRollVector(2) - -1.0) < testRollPrecision);

    // pitch 180 degrees
    Attitude attitudePitch(0, 0, 180, 0);
    Eigen::Matrix3d dcmFromAttitudePitchTest;
    CoordinateTransform::getDCM(dcmFromAttitudePitchTest,attitudePitch);
    Eigen::Vector3d testPitchVector = dcmFromAttitudePitchTest * testVector;

    double testPitchPrecision = 0.000000001;
    REQUIRE(abs(testPitchVector(0) - -1.0) < testPitchPrecision);
    REQUIRE(abs(testPitchVector(1) - 1.0) < testPitchPrecision);
    REQUIRE(abs(testPitchVector(2) - -1.0) < testPitchPrecision);

    // heading 180 degrees
    Attitude attitudeHeading(0, 0, 0, 180);
    Eigen::Matrix3d dcmFromAttitudeHeadingTest;
    CoordinateTransform::getDCM(dcmFromAttitudeHeadingTest,attitudeHeading);
    Eigen::Vector3d testHeadingVector = dcmFromAttitudeHeadingTest * testVector;

    double testHeadingPrecision = 0.000000001;
    REQUIRE(abs(testHeadingVector(0) - -1.0) < testHeadingPrecision);
    REQUIRE(abs(testHeadingVector(1) - -1.0) < testHeadingPrecision);
    REQUIRE(abs(testHeadingVector(2) - 1.0) < testHeadingPrecision);

    // random attitude
    double roll = 24.357;
    double pitch = 36.54;
    double heading = 157.43;
    Attitude attitudeRandom(0,roll, pitch, heading);
    Eigen::Matrix3d dcmFromAttitudeRandomTest;
    CoordinateTransform::getDCM(dcmFromAttitudeRandomTest,attitudeRandom);

    Eigen::Matrix3d dcmFromEulerAngles;
    dcmFromEulerAngles = Eigen::AngleAxisd(heading*D2R, Eigen::Vector3d::UnitZ())
      * Eigen::AngleAxisd(pitch*D2R, Eigen::Vector3d::UnitY())
      * Eigen::AngleAxisd(roll*D2R, Eigen::Vector3d::UnitX());

    double randomPrecision = 0.000000001;
    Eigen::Matrix3d dcmDifferences = dcmFromAttitudeRandomTest - dcmFromEulerAngles;
    dcmDifferences = dcmDifferences.cwiseAbs();
    REQUIRE(dcmDifferences.maxCoeff() < randomPrecision);
};

TEST_CASE("Test getPositionInNavigationFrame function")
{
    Eigen::Vector3d posNav;
    Position pos(0,0,0,0);
    Eigen::Matrix3d dcm;
    dcm << 0,0,0,
           0,0,0,
           0,0,0;
    Eigen::Vector3d origin(0,0,0);
    CoordinateTransform::getPositionInNavigationFrame(posNav,pos,dcm,origin);
    REQUIRE(posNav(0) == 0);
    REQUIRE(posNav(1) == 0);
    REQUIRE(posNav(2) == 0);
    
    pos = Position(0,180,180,0);
    dcm << 1,0,0,
           0,1,0,
           0,0,1;
    origin(0) = 0;
    origin(1) = 0;
    origin(2) = 0;
    CoordinateTransform::getPositionInNavigationFrame(posNav,pos,dcm,origin);
    Eigen::Vector3d vectorSearch(6378137,-0.0000000008,0.0000000008);
    REQUIRE(abs(posNav(0) - vectorSearch(0))< 1e-10);
    REQUIRE(abs(posNav(1) - vectorSearch(1))< 1e-10);
    REQUIRE(abs(posNav(2) - vectorSearch(2))< 1e-10);
}
